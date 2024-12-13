#include <fstream>
#include <climits>
#include <cctype>
#include <string>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int k,p,i;
unsigned long long sol;
long long t[2],a[2][2],d,b[2];
string s;
long long get_number(){
    long long n=0;
    while(isdigit(s[i])){
        n=n*10+s[i++]-'0';
    }
    return n;
}
int main()
{
    while(getline(cin,s)){
        i=0;
        p=0;
        if(s[i]==0)
            continue;
        if(s[i]=='P'){
            while(s[i]!=0){
                if(isdigit(s[i])){
                    b[p++]=get_number()+10000000000000;
                }else
                    i++;
            }
            d=a[0][0]*a[1][1]-a[0][1]*a[1][0];
            if((b[0]*a[1][1]-b[1]*a[1][0])%d==0&&(b[1]*a[0][0]-b[0]*a[0][1])%d==0)
                sol+=(b[0]*a[1][1]-b[1]*a[1][0])/d*3+(b[1]*a[0][0]-b[0]*a[0][1])/d;
            k=0;
        }else{
            while(s[i]!=0){
                if(isdigit(s[i])){
                    a[k][p++]=get_number();
                }else
                    i++;
            }
            k++;
        }
    }
    cout<<sol;
    return 0;
}
