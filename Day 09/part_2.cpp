#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,x,p,poz;
long long sol;
unordered_map<int,bool>viz;
string s;
vector<pair<int,int>>a;
struct cmp{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b){
        return a.first<b.first;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q[10];
void add(int x,int n){
    for(int j=1;j<=n;j++){
        sol+=1LL*p*x;
        p++;
    }
    viz[x]=1;
}
void move(int val){
    for(int i=val;i>0;i--){
        while(!q[i].empty()&&viz[q[i].top().first])
            q[i].pop();
        if(!q[i].empty()){
            add(q[i].top().first,q[i].top().second);
            val-=q[i].top().second;
            i=val+1;
        }
    }
    p+=val;
}
int main()
{
    cin>>s;
    n=s.size();
    if(n%2==0)
        n--;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]!='0'){
                a.push_back({x,s[i]-'0'});
                for(int j=s[i]-'0';j<10;j++)
                    q[j].push({x,s[i]-'0'});
                x++;
            }
        }else if(s[i]!='0')
            a.push_back({-1,s[i]-'0'});
    }
    n=a.size();
    for(int i=0;i<n;i++){
        if(a[i].first==-1){
            move(a[i].second);
        }else if(!viz[a[i].first])
            add(a[i].first,a[i].second);
        poz+=a[i].second;
        p=poz;
    }
    cout<<sol;
    return 0;
}
