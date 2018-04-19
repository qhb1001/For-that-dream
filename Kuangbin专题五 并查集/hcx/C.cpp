#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
const int maxn=1005;
int f[maxn],cnt[maxn];
int n,m;
void Init(){
    for(int i=1;i<=n;i++){
        f[i]=i;
        cnt[i]=1;
    }
}

int Find(int x){
    if(x!=f[x]){
        return f[x]=Find(f[x]);
    }
    return f[x];
}

void Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(a==b) return ;
    if(cnt[a]<cnt[b]){
        f[a]=b;
        cnt[b]+=cnt[a];
    }
    else{
        f[b]=a;
        cnt[a]+=cnt[b];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    int x,y;
    while(t--){
        cin>>n>>m;
        Init();
        for(int i=0;i<m;i++){
            cin>>x>>y;
            Union(x,y);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(f[i]==i){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

