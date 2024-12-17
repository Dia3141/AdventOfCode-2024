#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
ifstream fin("f.in");
ofstream fout("f.out");
long long a,b,c,B,C,op,r=LLONG_MAX;
int x,n;
vector<int>v,sol;
long long combo(int n){
    if(n<=3)
        return n;
    if(n==4)
        return a;
    if(n==5)
        return b;
    if(n==6)
        return c;
    return -1;
}
void solve(long long k){
    a=k,b=B,c=C;
    sol.clear();
    for(int i=0;i<n;i++){
        if(v[i]==0){
            if(i+1==n)
                continue;
            i++;
            op=combo(v[i]);
            a/=(1<<op);
        }else if(v[i]==1){
            if(i+1==n)
                continue;
            i++;
            b=(b^v[i]);
        }else if(v[i]==2){
            if(i+1==n)
                continue;
            i++;
            op=combo(v[i]);
            b=op%8;
        }else if(v[i]==3){
            if(i+1==n)
                continue;
            i++;
            if(a!=0)
                i=v[i]-1;
            else
                i--;
        }else if(v[i]==4){
            i++;
            b=(b^c);
        }else if(v[i]==5){
            if(i+1==n)
                continue;
            i++;
            op=combo(v[i]);
            sol.push_back(op%8);
        }else if(v[i]==6){
            if(i+1==n)
                continue;
            i++;
            op=combo(v[i]);
            b=a/(1<<op);
        }else{
            if(i+1==n)
                continue;
            i++;
            op=combo(v[i]);
            c=a/(1<<op);
        }
    }
}
bool verif(long long k,int l){
    solve(k);
    int j=0;
    for(int i=l;i<n;i++,j++)
        if(sol[j]!=v[i])
            return 0;
    return 1;
}
void rec(long long k,int l){
    if(l<0)
        return ;
    k*=8;
    for(int i=0;i<8;i++){
        if(verif(k+i,l)){
            rec(k+i,l-1);
            if(l==0)
                r=min(r,k+i);
        }
    }
}
int main()
{
    fin>>a>>b>>c;
    B=b,C=c;
    while(fin>>x)
        v.push_back(x);
    n=v.size();
    long long k=0;
    rec(k,n-1);
    fout<<r;
    return 0;
}
