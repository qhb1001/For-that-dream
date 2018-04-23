#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=30005;
int f[maxn];
int n,m;
void iniT(){
    for(int i=0;i<n;i++)
        f[i]=i;
}

int Find(int x){
    if(x!=f[x])
        return f[x]=Find(f[x]);
    else return f[x];
}

void Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(a<b) f[b]=a;
    else f[a]=b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m){
        if(!n)break;
        iniT();
        for(int i=0;i<m;i++){
            int k;cin>>k;
            int x;cin>>x;
            for(int i=1;i<k;i++){
                int y;cin>>y;
                Union(x,y);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(Find(i)==Find(0)){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
