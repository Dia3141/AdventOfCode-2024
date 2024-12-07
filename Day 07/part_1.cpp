#include <fstream>
#include <vector>
#include <cctype>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,i;
long long sol,a;
string s;
vector<long long>v;
bool ok;
long long get_number(){
    long long n=0;
    while(s[i]>='0'&&s[i]<='9'){
        n=n*10+s[i]-'0';
        i++;
    }
    return n;
}
void backtracking(int k,long long r){
    if(k==n){
        if(r==a)
            ok=0;
        return ;
    }
    if(!ok)
        return ;
    backtracking(k+1,r+v[k]);
    if(!ok)
        return ;
    backtracking(k+1,r*v[k]);
}
int main()
{
    while(getline(cin,s)){
        i=0;
        a=get_number();
        while(s[i]!=0){
            if(!isdigit(s[i]))
                i++;
            else
                v.push_back(get_number());
        }
        n=v.size();
        ok=1;
        backtracking(1,v[0]);
        if(!ok)
            sol+=a;
        v.clear();
    }
    cout<<sol;
    return 0;
}
