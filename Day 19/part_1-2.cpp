#include <fstream>
#include <unordered_map>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,maxi;
long long dp[100],part[2];
bool ok,found,d[100];
unordered_map<string,bool>mp;
string s;
int main()
{
    while(cin>>s){
        n=s.size();
        if(!ok){
            if(s[n-1]==',')
                s.pop_back(),n--;
            else
                ok=1;
            if(n>=1&&s[n-1]==' ')
                s.pop_back(),n--;
            mp[s]=1;
            maxi=max(maxi,n);
        }else{
            memset(dp,0,sizeof(dp));
            memset(d,0,sizeof(d));
            dp[0]=1;
            d[0]=1;
            for(int i=0;i<n;i++){
                string a="";
                for(int l=1;i+l<=n&&l<=maxi;l++){
                    a+=s[i+l-1];
                    if(dp[i]!=0&&mp[a])
                        dp[i+l]+=dp[i],d[i+l]=1;
                }
            }
            part[0]+=d[n];
            part[1]+=dp[n];
        }
    }
    cout<<part[0]<<'\n'<<part[1];
    return 0;
}
