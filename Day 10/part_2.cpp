#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,dx[]={-1,0,1,0},dy[]={0,1,0,-1},d[100][100];
bool viz[100][100];
string s;
vector<string>a;
queue<pair<int,int>>q;
long long sol;
bool inside(int l,int c){
    return l>=0&&c>=0&&l<n&&c<m;
}
int solve(int l,int c){
    int r=0;
    memset(d,0,sizeof(d));
    memset(viz,0,sizeof(viz));
    q.push({l,c});
    d[l][c]=1;
    while(!q.empty()){
        int  l=q.front().first,c=q.front().second;
        q.pop();
        if(a[l][c]=='9'){
            r+=d[l][c];
            continue;
        }
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i];
            if(inside(lv,cv)&&a[lv][cv]==a[l][c]+1){
                if(!viz[lv][cv]){
                    q.push({lv,cv});
                    viz[lv][cv]=1;
                }
                d[lv][cv]+=d[l][c];
            }
        }
    }
    return r;
}
int main()
{
    while(cin>>s){
        a.push_back(s);
    }
    n=a.size();
    m=a[0].size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='0')
                sol+=solve(i,j);
    cout<<sol;
    return 0;
}
