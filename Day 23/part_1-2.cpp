#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int n,x,y,maxi,nr,dim;
bool v[7000][7000];
vector<vector<int>>sir;
string s,a,b,cod[7000];
unordered_map<string,int>id;
bool Try(int x,int y){
    for(auto i:sir[y])
        if(!v[i][x])
            return 0;
    return 1;
}
int main()
{
    while(cin>>s){
        a=b="";
        a+=s[0],a+=s[1];
        if(id.find(a)==id.end()){
            cod[n]=a;
            id[a]=n++;
        }
        x=id[a];
        b+=s[3],b+=s[4];
        if(id.find(b)==id.end()){
            cod[n]=b;
            id[b]=n++;
        }
        y=id[b];
        v[x][y]=v[y][x]=1;
    }
    for(int i=0;i<n;i++){
        int newd=0;
        for(int j=0;j<dim;j++){
                if(Try(i,j)){
                    sir.push_back(sir[j]);
                    newd++;
                    sir[j].push_back(i);
                }
            }
            dim+=newd;
            dim++;
            sir.push_back({i});
    }
    for(int i=0;i<dim;i++){
        if(sir[i].size()>maxi){
            maxi=sir[i].size();
            nr=i;
        }
    }
    for(int i=0;i<maxi;i++)
        for(int j=0;j<maxi;j++)
            if(cod[sir[nr][i]]<cod[sir[nr][j]])
                swap(sir[nr][i],sir[nr][j]);
    for(int i=0;i<maxi-1;i++)
        cout<<cod[sir[nr][i]]<<',';
    cout<<cod[sir[nr][maxi-1]];
    return 0;
}
