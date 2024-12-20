#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,dpf[200][200],dps[200][200],ls,cs,lf,cf,sol,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
string s;
vector<string>a;
struct cmp{
    bool operator()(const pair<pair<int,int>,pair<int,int>>& a, const pair<pair<int,int>,pair<int,int>>& b){
        return a.second>b.second;
    }
};
priority_queue<pair<pair<int,int>,pair<int,int>>,vector<pair<pair<int,int>,pair<int,int>>>,cmp>q;
bool inside(int l,int c){
    return l>=0&&c>=0&&l<=n-1&&c<=m-1;
}
void find(char ch,int& l,int& c){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]==ch){
                l=i,c=j;
                return ;
            }
}
void dijkstra(int dp[][200],int l,int c){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j]=1e9;
    q.push({{l,c},{0,0}});
    dp[l][c]=0;
    while(!q.empty()){
        int l=q.top().first.first,c=q.top().first.second;
        q.pop();
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i];
            if(inside(lv,cv)&&a[lv][cv]!='#'&&dp[lv][cv]>dp[l][c]+1){
                dp[lv][cv]=dp[l][c]+1;
                q.push({{lv,cv},{dp[lv][cv],0}});
            }
        }
    }
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
    a[lf][cf]=a[ls][cs]='.';
    dijkstra(dps,ls,cs);
    dijkstra(dpf,lf,cf);
    for(int i=1;i<n-1;i++)
        for(int j=1;j<m-1;j++)
            if(a[i][j]=='.'){
                for(int x=-20;x<=20;x++)
                    for(int y=-20;y<=20;y++){
                        int lv=i+x,cv=j+y;
                        if(abs(x)+abs(y)>=2&&abs(x)+abs(y)<=20&&inside(lv,cv)&&a[lv][cv]=='.'&&dps[i][j]+dpf[lv][cv]+abs(x)+abs(y)<=dps[lf][cf]-100)
                            sol++;
                    }
            }
    cout<<sol;
    return 0;
}
