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
void solve(int l,int c,char x){
    for(auto i: v[x])
        if((i.l!=l||i.c!=c)){
            int dx=abs(i.l-l),dy=abs(i.c-c),lv,cv;
            if(i.l<l||(i.l==l&&i.c<c)){
                lv=i.l-dx;
                if(i.c<c)
                    cv=i.c-dy;
                else
                    cv=i.c+dy;
            }else{
                lv=l-dx;
                if(c<i.c)
                    cv=c-dy;
                else
                    cv=c+dy;
            }
            if(inside(lv,cv)&&d[lv][cv]==0)
                sol++,d[lv][cv]=1;
            if(i.l>l||(i.l==l&&i.c>c)){
                lv=i.l+dx;
                 if(i.c>c)
                    cv=i.c+dy;
                else
                    cv=i.c-dy;
            }else{
                lv=l+dx;
                if(c>i.c)
                    cv=c+dy;
                else
                    cv=c-dy;
            }
            if(inside(lv,cv)&&d[lv][cv]==0)
                sol++,d[lv][cv]=1;
        }
}
void afisare(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[i][j];
        cout<<'\n';
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
