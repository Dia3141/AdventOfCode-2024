#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream fin("f.in");
ofstream fout("f.out");
int n;
long long sol,rez;
struct op{
    int tip;
    string a,b,c;
};
vector<op>v;
set<int>s1,to_erase;
bool z[50],x[50],y[50],viz[300],found;
string s,aux,sir[10],r[10];
unordered_map<string,bool>mp;
unordered_map<string,vector<int>>p;
bool cmp(const op& a,const op& b){
    return a.c<b.c;
}
int main()
{
    while(getline(fin,s)){
        if(s[0]==0)
            continue;
        else if(s[3]==':'){
            aux="";
            aux+=s[0],aux+=s[1],aux+=s[2];
            mp[aux]=(bool)(s[5]-'0');
            if(s[0]=='x')
                x[(s[1]-'0')*10+s[2]-'0']=mp[aux];
            else if(s[0]=='y')
                y[(s[1]-'0')*10+s[2]-'0']=mp[aux];
        }else{
            v.push_back({});
            v[n].a+=s[0],v[n].a+=s[1],v[n].a+=s[2];
            int i=7;
            if(s[4]=='O')
                v[n].tip=1;
            else if(s[4]=='A')
                i++,v[n].tip=0;
            else
                i++,v[n].tip=2;
            v[n].b+=s[i],v[n].b+=s[i+1],v[n].b+=s[i+2];
            v[n].c+=s[i+7],v[n].c+=s[i+8],v[n].c+=s[i+9];
            s1.insert(n);
            n++;
        }
    }
    for(int i=0;i<46;i++){
        if(x[i])
            rez+=(1LL<<i);
        if(y[i])
            rez+=(1LL<<i);
    }
    for(int i=45;i>=0;i--)
        fout<<i%10;
    fout<<'\n';
    for(int i=45;i>=0;i--)
        if(rez&(1LL<<i))
            fout<<1;
        else
            fout<<0;
    fout<<'\n'<<rez<<'\n';
    sort(v.begin(),v.end(),cmp);
    int t=0;
    while(t!=n){
        int last=t;
        for(auto i:s1)
            if(mp.find(v[i].a)!=mp.end()&&mp.find(v[i].b)!=mp.end()){
                if(v[i].tip==1)
                    mp[v[i].c]=(bool)(mp[v[i].a]||mp[v[i].b]);
                else if(v[i].tip==0)
                    mp[v[i].c]=(bool)(mp[v[i].a]&&mp[v[i].b]);
                else
                    mp[v[i].c]=(bool)(mp[v[i].a]^mp[v[i].b]);
                if(v[i].c[0]=='z')
                    z[(v[i].c[1]-'0')*10+v[i].c[2]-'0']=mp[v[i].c];
                t++;
                to_erase.insert(i);
            }
        for(auto i:to_erase)
            s1.erase(i);
        if(last==t){
            cout<<"broke";
            return 0;
        }
    }
    for(int i=45;i>=0;i--){
        if(z[i])
            sol+=(1LL<<i);
    }
    fout<<'\n'<<sol;
    return 0;
}
/// fiecare z trebuie calculat ca a XOR b => in input exista exact 3 z ce nu respecta aceasta regula
/// pentru fiecare z ce nu respecta regula procedam astfel
/// scriem ecuatia pentru z[i]  fie aceasta : mvs AND jvj -> z10
/// scriem o ecuatie de forma x[i] XOR y[i] -> r fie acesta : x10 XOR y10 -> jvj
/// scriem o ecuatie ce contine pe r fie aceasta : jvj XOR mvs -> mbk
/// se va da swap intere z[i] si rezultatul ecuatie ce contine pe r, pe exemplul de mai sus : swap(z10,mbk)
