#include <fstream>
#include <vector>
#include <string>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,p,t,last,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
long long sol;
bool d[200][200];
char ch;
vector<string>a;
string s;
bool inside(int l,int c){
    return l>=0&&c>=0&&l<n&&c<m;
}
void Fill(int l,int c){
    d[l][c]=1;
    t++;
    bool ok[4]={0,0,0,0};
    for(int i=0;i<4;i++){
        int lv=l+dx[i],cv=c+dy[i];
        if(inside(lv,cv)&&a[lv][cv]==ch){
            if(!d[lv][cv])
                Fill(lv,cv);
            ok[i]=1;
        }
    }
    if(!ok[3]&&!ok[0])
        p++;
    if(!ok[3]&&!ok[2])
        p++;
    if(!ok[1]&&!ok[2])
        p++;
    if(!ok[0]&&!ok[1])
        p++;
    if(ok[3]&&ok[0]&&(inside(l-1,c+1)&&a[l-1][c+1]!=ch))
        p++;
    if(ok[1]&&ok[0]&&(inside(l+1,c+1)&&a[l+1][c+1]!=ch))
        p++;
    if(ok[3]&&ok[2]&&(inside(l-1,c-1)&&a[l-1][c-1]!=ch))
        p++;
    if(ok[1]&&ok[2]&&(inside(l+1,c-1)&&a[l+1][c-1]!=ch))
        p++;
}
int main()
{
    while(cin>>s)
        a.push_back(s);
    n=a.size();
    m=a[0].size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!d[i][j]){
                ch=a[i][j];
                p=t=0;
                Fill(i,j);
                sol+=1LL*t*p;
                //cout<<t<<" "<<p<<'\n';
            }
    cout<<sol;
    return 0;
}
