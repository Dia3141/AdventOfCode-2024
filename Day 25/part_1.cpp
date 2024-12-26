#include <fstream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
ifstream cin("f.in");
ofstream cout("f.out");
int sol;
string a[7];
struct elem{
    int nr[5];
};
vector<elem>lock,key;
bool verif_lock(){
    for(int i=0;i<5;i++)
        if(a[0][i]!='#')
            return 0;
    return 1;
}
bool Try(int a,int b){
    for(int i=0;i<5;i++)
        if(lock[a].nr[i]+key[b].nr[i]>7)
            return 0;
    return 1;
}
int main()
{
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]){
        elem nr={0,0,0,0,0};
        for(int i=0;i<7;i++){
            for(int j=0;j<5;j++)
                nr.nr[j]+=(a[i][j]=='#');
        }
        if(verif_lock())
            lock.push_back(nr);
        else
            key.push_back(nr);
    }
    int n=lock.size(),m=key.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            sol+=Try(i,j);
    cout<<sol;
    return 0;
}
