#include <fstream>
#include <deque>
#include <unordered_map>
#include <cmath>
#define mod 16777216
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
struct elem{
    int a,b,c,d;
    bool operator==(const elem& k) const {
        return a == k.a && b == k.b && c == k.c && d == k.d;
    }
}a;
namespace std {
    template <>
    struct hash<elem> {
        size_t operator()(const elem& key) const {
            return ((hash<int>()(key.a) ^ (hash<int>()(key.b) << 1)) >> 1) ^
                   (hash<int>()(key.c) ^ (hash<int>()(key.d) << 1));
        }
    };
}
deque<int>secv;
unordered_map<elem,long long>s[2500],sum;
long long y,x,sol,v[2001],n;
int main()
{
    while(cin>>x){
        secv.clear();
        v[0]=x%10;
        for(int i=1;i<=2000;i++){
            y=x*64;
            x=(x^y)%mod;
            y=floor(x/32);
            x=(x^y)%mod;
            y=x*2048;
            x=(x^y)%mod;
            v[i]=x%10;
            if(i>4)
                secv.pop_front();
            secv.push_back(v[i]-v[i-1]);
            if(i>=4){
                a={secv[0],secv[1],secv[2],secv[3]};
                if(s[n].find(a)==s[n].end()){
                    s[n][a]=v[i],sum[a]+=v[i];
                    sol=max(sol,sum[a]);
                }
            }
        }
        n++;
    }
    cout<<sol;
    return 0;
}
