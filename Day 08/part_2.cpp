#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,sol,d[70][70];
string s;
vector<string>a;
struct elem{
    int l,c;
};
vector<elem>v[256];
bool inside(int l,int c){
    return l>=0&&c>=0&&l<n&&c<m;
}
void path(int l,int c,int dx,int dy){
    while(inside(l,c)){
        if(d[l][c]==0)
            sol++,d[l][c]=1;
        l+=dx,c+=dy;
    }
}
void solve(int l,int c,char x){
    if(!v[x].empty()&&d[l][c]==0)
        sol++,d[l][c]=1;
    for(auto i: v[x])
        if((i.l!=l||i.c!=c)){
            int dx=abs(i.l-l),dy=abs(i.c-c);
            if(i.l<l||(i.l==l&&i.c<c)){
                if(i.c<c)
                    path(i.l-dx,i.c-dy,-dx,-dy);
                else
                    path(i.l-dx,i.c+dy,-dx,dy);
            }else{
                if(c<i.c)
                    path(l-dx,c-dy,-dx,-dy);
                else
                    path(l-dx,c+dy,-dx,dy);
            }
            if(i.l>l||(i.l==l&&i.c>c)){
                 if(i.c>c)
                    path(i.l+dx,i.c+dy,dx,dy);
                else
                    path(i.l+dx,i.c-dy,dx,-dy);
            }else{
                if(c>i.c)
                    path(l+dx,c+dy,dx,dy);
                else
                    path(l+dx,c-dy,dx,-dy);
            }
        }
}
int main()
{
    while(cin>>s)
        a.push_back(s);
    n=a.size();
    m=a[0].size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]!='.')
                v[a[i][j]].push_back({i,j});
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]!='.'){
                solve(i,j,a[i][j]);
            }
        }
    }
    cout<<sol;
    return 0;
}
