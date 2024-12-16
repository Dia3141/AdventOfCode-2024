#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#define dim 200000
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,ls,cs,lf,cf,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
long long dp[200][200][4];
vector<string>a;
string s;
bool ok;
struct cmp{
    bool operator()(const pair<pair<int,int>,pair<int,int>>& a,const pair<pair<int,int>,pair<int,int>>& b){
        return a.second.second>b.second.second;
    }
};
priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,cmp>heap;
queue<pair<pair<int,int>,int>>q;
void find(char ch,int& l,int& c){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]==ch){
                l=i,c=j;
                return ;
            }
}
bool inside(int l,int c){
    return l>=0&&c>=0&&l<n&&c<m;
}
void initializare(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<4;k++)
                dp[i][j][k]=LLONG_MAX;
}
void dijkstra(){
    initializare();
    heap.push({{ls,cs},{0,0}});
    dp[ls][cs][0]=0;
    while(!heap.empty()){
        int l=heap.top().first.first,c=heap.top().first.second,dir=heap.top().second.first;
        heap.pop();
        if(a[l][c]=='E'&&!ok){
            cout<<dp[l][c][dir]<<'\n';
            ok=1;
        }
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i],cost=1+(dir!=i)*1000;
            if(inside(lv,cv)&&a[lv][cv]!='#'&&dp[lv][cv][i]>dp[l][c][dir]+cost){
                dp[lv][cv][i]=dp[l][c][dir]+cost;
                if(dir!=i){
                    dp[l][c][i]=min(dp[l][c][i],dp[l][c][dir]+1000);
                }
                heap.push({{lv,cv},{i,dp[lv][cv][i]}});
            }
        }
    }
}
void path(){
    q.push({{lf,cf},3});
    while(!q.empty()){
        int l=q.front().first.first,c=q.front().first.second,dir=q.front().second;
        q.pop();
        a[l][c]='O';
        for(int i=0;i<4;i++){
            int dir2=(i+2)%4,lv=l+dx[i],cv=c+dy[i],cost=1+(dir!=dir2)*1000;
            if(inside(lv,cv)&&a[lv][cv]!='#'&&dp[lv][cv][dir2]+cost==dp[l][c][dir])
                q.push({{lv,cv},dir2});
        }
    }
}
int count(){
    int r=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            r+=(a[i][j]=='O');
    return r;
}
void afisare(){
    for(auto i:a)
        cout<<i<<'\n';
}
int main()
{
    while(cin>>s){
        a.push_back(s);
    }
    n=a.size();
    m=a[0].size();
    find('S',ls,cs);
    find('E',lf,cf);
    dijkstra();
    path();
    cout<<count()<<'\n';
    afisare();
    return 0;
}
