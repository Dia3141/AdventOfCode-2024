#include <fstream>
#include <vector>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,m,x;
long long sol;
vector<long long>v[2];
int verif(long long n){
    int r=0;
    while(n!=0)
        r++,n/=10;
    return r;
}
void split(long long n,int k,int c){
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
    v[(k+1)%2].push_back(r2);
    v[(k+1)%2].push_back(r1);
}
int main()
{
    n=8;
    for(int i=0;i<n;i++){
        cin>>x;
        v[1].push_back(x);
    }
    for(int k=1;k<=25;k++){
        v[(k+1)%2].clear();
        for(auto i:v[k%2]){
            int c=verif(i);
            if(c==0)
                v[(k+1)%2].push_back(1);
            else if(c%2!=0)
                v[(k+1)%2].push_back(i*2024);
            else
                split(i,k,c);
        }
        n=v[(k+1)%2].size();
    }
    cout<<v[0].size();
    return 0;
}
