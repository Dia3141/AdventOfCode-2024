#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int v[][2]={{3,1},{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2},{3,2}},v2[][2]={{1,2},{1,1},{1,0},{0,1},{0,2}};
int a[][3]={{7,8,9},{4,5,6},{1,2,3},{0,0,10}},a2[][3]={{0,3,4},{2,1,0}};
unsigned long long sol,dp[12][12],dp2[5][5],dist[5][5],d,nr;
char tip,ch,ch2;
string s;
bool inside(int l,int c){
    return l>=0&&c>=0&&l<4&&c<3&&!(l==3&&c==0);
}
bool inside2(int l,int c){
    return l>=0&&c>=0&&l<2&&c<3&&!(l==0&&c==0);
}
void initializare(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            dist[i][j]=dp2[i][j];
}
struct cmp{
    bool operator()(const pair<pair<int,int>,unsigned long long>& a,const pair<pair<int,int>,unsigned long long>& b){
        return a.second>b.second;
    }
};
priority_queue<pair<pair<int,int>,unsigned long long>,vector<pair<pair<int,int>,unsigned long long>>,cmp>q;
void dijkstra(int k,int l,int c){
    for(int i=0;i<11;i++)
        dp[k][i]=ULLONG_MAX;
    q.push({{k,4},0});
    dp[k][k]=0;
    while(!q.empty()){
        int t=q.top().first.first,p=q.top().first.second,d=q.top().second;
        l=v[t][0],c=v[t][1];
        q.pop();
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i];
            unsigned long long cost=dp2[p][i]+dp2[i][4]+1;
            if(!inside(lv,cv))
                continue;
            int t1=a[lv][cv];
            if(dp[k][t1]>d+cost){
                dp[k][t1]=d+cost;
                q.push({{t1,i},dp[k][t1]-dp2[i][4]});
            }
        }
    }
}
void dijkstra2(int k,int l,int c){
    for(int i=0;i<5;i++)
        dp2[k][i]=ULLONG_MAX;
    q.push({{k,4},0});
    dp2[k][k]=0;
    while(!q.empty()){
        int t=q.top().first.first,p=q.top().first.second,d=q.top().second;
        l=v2[t][0],c=v2[t][1];
        q.pop();
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i];
            unsigned long long cost=dist[p][i]+dist[i][4]+1;
            if(!inside2(lv,cv))
                continue;
            int t1=a2[lv][cv];
            if(dp2[k][t1]>d+cost){
                dp2[k][t1]=d+cost;
                q.push({{t1,i},dp2[k][t1]-dist[i][4]});
            }
        }
    }
}
void afisare(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<dist[i][j]<<" ";
        cout<<'\n';
    }
    cout<<'\n';
}
int main()
{
    dist[0][1]=dist[1][0]=dist[1][2]=dist[2][1]=dist[1][3]=dist[3][1]=dist[3][4]=dist[4][3]=dist[4][0]=dist[0][4]=1;
    dist[0][2]=dist[2][0]=dist[3][0]=dist[0][3]=dist[1][4]=dist[4][1]=dist[2][3]=dist[3][2]=2;
    dist[2][4]=dist[4][2]=3;
    /// precalculez cate miscari as face de pe placa mea pentru a muta robotul de pe placa de directii j de pe o pozitie pe oricare alta din cadrul placii
    for(int j=1;j<2;j++){
        for(int i=0;i<5;i++)
            dijkstra2(i,v2[i][0],v2[i][1]);
        initializare();
        afisare();
    }
    /// precalculez cate miscari as face de pe placa mea pentru a muta robotul de pe placa de baza din pozitia i in pozitia j
    for(int i=0;i<11;i++)
        dijkstra(i,v[i][0],v[i][1]);
    for(int i=0;i<11;i++){
        for(int j=0;j<11;j++)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }
    while(cin>>s){
        d=nr=0;
        tip='A';
        for(int i=0;s[i]!=0;i++){
            if(s[i]!=tip){
                ch2=s[i],ch=tip;
                if(s[i]=='A')
                    ch2='0'+10;
                if(tip=='A')
                    ch='0'+10;
                d+=dp[ch-'0'][ch2-'0'];
                tip=s[i];
            }
            d++;
            if(s[i]!='A')
                nr=nr*10+s[i]-'0';
        }
        sol+=nr*d;
    }
    cout<<sol;
    return 0;
}
