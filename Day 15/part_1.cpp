#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,t,l,c,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
long long sol;
string s,dir;
vector<string>a,cl;
void coord(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='@'){
                l=i,c=j;
                return ;
            }
}
bool inside(int l,int c){
    return l>0&&c>0&&l<n-1&&c<m-1;
}
void move(int i){
    int lv=l+dx[i],cv=c+dy[i];
    if(!inside(lv,cv))
        return ;
    if(a[lv][cv]=='.'){
        swap(a[l][c],a[lv][cv]);
        l=lv,c=cv;
    }else if(a[lv][cv]=='O'){
        int l1=lv,c1=cv;
        while(inside(l1,c1)&&a[l1][c1]=='O')
            l1+=dx[i],c1+=dy[i];
        if(inside(l1,c1)&&a[l1][c1]=='.'){
            swap(a[l1][c1],a[lv][cv]);
            swap(a[l][c],a[lv][cv]);
            l=lv,c=cv;
        }
    }
}
int main()
{
    while(cin>>s){
        if(s[0]=='#')
            a.push_back(s);
        else
            dir+=s;
    }
    n=a.size();
    m=a[0].size();
    coord();
    t=dir.size();
    for(int i=0;i<t;i++){
        int k=0;
        if(dir[i]=='^')
            k=3;
        else if(dir[i]=='>')
            k=0;
        else if(dir[i]=='<')
            k=2;
        else
            k=1;
        move(k);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='O')
                sol+=100*i+j;
        }
    }
    cout<<sol;
    return 0;
}
