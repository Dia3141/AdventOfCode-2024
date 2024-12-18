#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#include <cctype>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,x,y,i,a[100][100],dp[100][100],dx[]={0,1,0,-1},dy[]={1,0,-1,0};
string s;
vector<pair<int,int>>v;
queue<pair<int,int>>q;
int get_number(){
    int n=0;
    while(isdigit(s[i])){
        n=n*10+s[i]-'0';
        i++;
    }
    return n;
}
bool inside(int l,int c){
    return l>=0&&c>=0&&l<=n&&c<=m;
}
void lee(){
    dp[0][0]=1;
    q.push({0,0});
    while(!q.empty()){
        int l=q.front().first,c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i];
            if(inside(lv,cv)&&a[lv][cv]==0&&(dp[lv][cv]==0||dp[lv][cv]>dp[l][c]+1)){
                q.push({lv,cv});
                dp[lv][cv]=dp[l][c]+1;
            }
        }
    }
}
int main()
{
    n=m=70;
    while(cin>>s){
        i=0;
        y=get_number();
        i++;
        x=get_number();
        v.push_back({x,y});
    }
    for(int i=0;i<1024;i++)
        a[v[i].first][v[i].second]=-1;
    lee();
    cout<<dp[70][70]-1<<'\n';
    int k=v.size();
    for(int i=1024;i<k;i++){
        a[v[i].first][v[i].second]=-1;
        memset(dp,0,sizeof(dp));
        lee();
        if(dp[70][70]==0){
            cout<<v[i].second<<","<<v[i].first;
            return 0;
        }
    }
    return 0;
}
