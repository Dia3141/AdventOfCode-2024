#include <fstream>
#include <vector>
#include <cctype>
#include <cstring>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int sol,d[200][200],c[4],i,n,m,k;
struct elem{
    int l,c,x,y;
};
vector<elem>v;
string s;
int get_number(){
    int n=0,semn=1;
    if(s[i]=='-')
        semn=-1,i++;
    while(isdigit(s[i])){
        n=n*10+s[i++]-'0';
    }
    return n*semn;
}
void solve(){
    for(int i=0;i<k;i++){
        d[v[i].l][v[i].c]--;
        v[i].l+=v[i].x;
        v[i].c+=v[i].y;
        if(v[i].l>=n)
            v[i].l-=n;
        if(v[i].l<0)
            v[i].l+=n;
        if(v[i].c>=m)
            v[i].c-=m;
        if(v[i].c<0)
            v[i].c+=m;
        d[v[i].l][v[i].c]++;
    }
}
// part 2
bool verif(){
    for(int i=0;i<n;i++){
        int maxi=0,l=0;
        for(int j=0;j<m;j++)
            if(d[i][j]!=0){
                l++;
                maxi=max(maxi,l);
            }else
                l=0;
        if(maxi>10)
            return 1;
    }
    return 0;
}
int main()
{
    n=103,m=101;
    while(getline(cin,s)){
        i=0;
        v.push_back({0,0,0,0});
        while(s[i]!=0){
            if(s[i]=='p'){
                i+=2;
                v[k].c=get_number();
                i++;
                v[k].l=get_number();
                d[v[k].l][v[k].c]++;
            }else if(s[i]=='v'){
                i+=2;
                v[k].y=get_number();
                i++;
                v[k].x=get_number();
            }else
                i++;
        }
        k++;
    }
    k=v.size();
    for(int t=1;t<=10000;t++){
        solve();
        // part 2
        if(verif()){
            cout<<"id "<<t<<'\n';
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)
                    if(d[i][j]!=0)
                        cout<<'#';
                    else
                        cout<<'.';
                cout<<'\n';
            }
            cout<<'\n'<<'\n';
        }
    }
    // part 1
    for(auto i:v){
        if(i.l<n/2&&i.c<m/2)
            c[0]++;
        else if(i.l<n/2&&i.c>m/2)
            c[1]++;
        else if(i.l>n/2&&i.c<m/2)
            c[2]++;
        else if(i.l>n/2&&i.c>m/2)
            c[3]++;
    }
    cout<<1LL*c[0]*c[1]*c[2]*c[3];
    return 0;
}
