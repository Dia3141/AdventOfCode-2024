#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int sol,l1,c1,n,m,dx[]={-1,0,1,0},dy[]={0,1,0,-1},dp[150][150][4];
string s;
vector<string>a;
void find_place(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='^'){
                l1=i,c1=j;
                return ;
            }
}
bool inside(int l,int c){
    return l>=0&&c>=0&&l<n&&c<m;
}
void initializare(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=dp[i][j][3]=(a[i][j]=='#')*(2);
}
bool solve(int l,int c,int d){
    initializare();
    while(inside(l,c)){
        if(dp[l][c][d]==1)
            return 1;
        else if(dp[l][c][d]==0){
            dp[l][c][d]=1;
            l+=dx[d],c+=dy[d];
        }else{
            l-=dx[d],c-=dy[d];
            d=(d+1)%4;
            l+=dx[d],c+=dy[d];
        }
    }
    return 0;
}
int main()
{
    while(cin>>s)
        a.push_back(s);
    n=a.size();
    m=a[0].size();
    find_place();
    a[l1][c1]='.';
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]!='#'&&!(l1==i&&c1==j)){
                a[i][j]='#';
                sol+=solve(l1,c1,0);
                a[i][j]='.';
            }
    cout<<sol;
    return 0;
}
