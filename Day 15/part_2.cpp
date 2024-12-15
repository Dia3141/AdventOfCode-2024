#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,t,l,c,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
long long sol;
bool ok;
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
    return l>=0&&c>=0&&l<n&&c<m;
}
void rec(int l,int c,int i){
    int lv=l+dx[i],cv=c+dy[i];
    if(!inside(lv,cv)||cl[lv][cv]=='#'||cl[lv][cv+1]=='#'){
        ok=0;
        return ;
    }
    if(cl[lv][cv]=='['||cl[lv][cv]==']'){
        if(cl[lv][cv]==']')
            cv--;
        rec(lv,cv,i);
    }
    cv=c+dy[i];
    if(cl[lv][cv+1]=='[')
        rec(lv,cv+1,i);
    if(cl[lv][cv]=='.'&&cl[lv][cv+1]=='.'){
        swap(cl[lv][cv],cl[l][c]);
        swap(cl[lv][cv+1],cl[l][c+1]);
    }else ok=0;
}
void move(int i){
    int lv=l+dx[i],cv=c+dy[i];
    if(!inside(lv,cv))
        return ;
    if(a[lv][cv]=='.'){
        swap(a[l][c],a[lv][cv]);
        l=lv,c=cv;
    }else if(a[lv][cv]=='['||a[lv][cv]==']'){
        if(i%2==0){
            int c1=cv;
            while(inside(l,c1)&&(a[l][c1]=='['||a[l][c1]==']'))
                c1+=dy[i];
            if(inside(l,c1)&&a[l][c1]=='.'){
                if(i==0){
                    for(int k=max(c1,cv);k>min(c1,cv);k--)
                        a[l][k]=a[l][k-1];
                }else{
                    for(int k=min(c1,cv);k<max(c1,cv);k++)
                        a[l][k]=a[l][k+1];
                }
                a[lv][cv]='@';
                a[l][c]='.';
                l=lv,c=cv;
            }
            return;
        }
        if(a[lv][cv]==']')
            cv--;
        ok=1;
        for(int i=0;i<n;i++)
            cl[i]=a[i];
        rec(lv,cv,i);
        if(ok){
            for(int i=0;i<n;i++)
                a[i]=cl[i];
            lv=l+dx[i],cv=dy[i]+c;
            swap(a[lv][cv],a[l][c]);
            l=lv,c=cv;
        }
    }
}
void change(){
    for(int i=0;i<n;i++){
        a.push_back("");
        for(int j=0;j<m;j++)
            if(cl[i][j]=='#')
                a[i].push_back('#'),a[i].push_back('#');
            else if(cl[i][j]=='.')
                a[i].push_back('.'),a[i].push_back('.');
            else if(cl[i][j]=='O')
                a[i].push_back('['),a[i].push_back(']');
            else if(cl[i][j]=='@')
                a[i].push_back('@'),a[i].push_back('.');
    }
}
void afisare(){
    for(int i=0;i<n;i++)
        cout<<a[i]<<'\n';
    cout<<'\n';
}
int main()
{
    while(cin>>s){
        if(s[0]=='#')
            cl.push_back(s);
        else
            dir+=s;
    }
    n=cl.size();
    m=cl[0].size();
    change();
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
        //afisare();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='[')
                sol+=100*i+j;
        }
    }
    cout<<sol;
    return 0;
}
