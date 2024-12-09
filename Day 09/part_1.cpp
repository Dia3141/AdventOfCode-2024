#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,x;
long long sol;
string s;
vector<int>a;
int main()
{
    cin>>s;
    n=s.size();
    if(n%2==0)
        n--;
    for(int i=0;i<n;i++){
        for(int j=1;j<=s[i]-'0';j++)
            if(i%2==0)
                a.push_back(x);
            else
                a.push_back(-1);
        if(i%2==0&&s[i]!=0)
            x++;
    }
    n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==-1){
            while(a[n-1]==-1&&i+1!=n)
                a[n-1]=0,n--;
            a[i]=a[n-1];
            a[n-1]=0;
            n--;
        }
        if(a[i]!=-1)
            sol+=1LL*i*a[i];
    }
    cout<<sol;
    return 0;
}
