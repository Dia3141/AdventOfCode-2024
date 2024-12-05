#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int a,i;
long long sol;
vector<int>v;
unordered_map<int,bool>m[101];
string s;
int get_number(){
    int n=0;
    while(s[i]>='0'&&s[i]<='9'){
        n=n*10+s[i]-'0';
        i++;
    }
    return n;
}
void solve(){
    v.clear();
    v.push_back(a);
    bool ok=1;
    while(s[i]!=0){
        i++;
        a=get_number();
        for(auto j:v)
            if(m[a][j])
                ok=0;
        v.push_back(a);
    }
    if(ok)
        return ;
    int n=v.size();
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++)
            if(m[v[j]][v[i]]){
                swap(v[i],v[j]);
                i=j+1;
                break;
            }
    }
    sol+=v[n/2];
}
int main()
{
    while(cin>>s){
        i=0;
        a=get_number();
        if(s[i]=='|'){
            i++;
            m[a][get_number()]=1;
        }else
            solve();
    }
    cout<<sol;
    return 0;
}
