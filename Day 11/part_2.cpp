#include <fstream>
#include <unordered_map>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,x;
long long sol;
unordered_map<long long,long long>mp[2],c;
long long verif(long long n){
    long long r=0;
    if(n==0)
        return -1;
    while(n!=0)
        r++,n/=10;
    return r;
}
void split(long long n,long long t,int k,int c){
    long long r1=0,p=1;
    for(int i=1;i<=c/2;i++){
        r1=r1+n%10*p;
        n/=10;
        p*=10;
    }
    long long r2=0;
    p=1;
    for(int i=1;i<=c/2;i++){
        r2=r2+n%10*p;
        n/=10;
        p*=10;
    }
    mp[(k+1)%2][r2]+=t;
    mp[(k+1)%2][r1]+=t;
}
int main()
{
    n=8;
    for(int i=0;i<n;i++){
        cin>>x;
        mp[1][x]++;
    }
    for(int k=1;k<=75;k++){
        mp[(k+1)%2].clear();
        for(auto i:mp[k%2]){
            if(c[i.first]==0)
                c[i.first]=verif(i.first);
            if(c[i.first]==-1)
                mp[(k+1)%2][1]+=i.second;
            else if(c[i.first]%2!=0)
                mp[(k+1)%2][i.first*2024]+=i.second;
            else
                split(i.first,i.second,k,c[i.first]);
        }
    }
    for(auto i:mp[0])
        sol+=i.second;
    cout<<sol;
    return 0;
}
