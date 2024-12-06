#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int sol,l1,c1,n,m,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
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
void solve(int l,int c,int d){
    sol++;
    a[l][c]='1';
    while(inside(l,c)){
        if(a[l][c]=='#'){
            l-=dx[d],c-=dy[d];
            d=(d+1)%4;
        }else if(a[l][c]=='.')
            a[l][c]='1',sol++;
        l+=dx[d],c+=dy[d];
    }
}
int main()
{
    while(cin>>s)
        a.push_back(s);
    n=a.size();
    m=a[0].size();
    find_place();
    solve(l1,c1,0);
    cout<<sol;
    return 0;
}
