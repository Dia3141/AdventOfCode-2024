#include <fstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,p,t,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
long long sol;
bool d[200][200];
char ch;
vector<string>a;
string s;
bool inside(int l,int c){
    return l>=0&&c>=0&&l<n&&c<m;
}
queue<pair<int,int>>q;
void Fill(int l,int c){
    q.push({l*1000+c,0});
    d[l][c]=1;
    while(!q.empty()){
        int l=q.front().first/1000,c=q.front().first%1000,dad=q.front().second;
        q.pop();
        t++;
        for(int i=0;i<4;i++){
            int lv=l+dx[i],cv=c+dy[i];
            if(inside(lv,cv)&&a[lv][cv]==ch)
                if(!d[lv][cv]){
                    p+=2;
                    d[lv][cv]=1;
                    q.push({lv*1000+cv,l*1000+c});
                }else if(dad/1000!=lv||dad%1000!=cv)
                    p--;
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
            if(!d[i][j]){
                ch=a[i][j];
                p=4;
                t=0;
                Fill(i,j);
                sol+=1LL*p*t;
                //cout<<p<<" "<<t<<'\n';
            }
    cout<<sol;
    return 0;
}
