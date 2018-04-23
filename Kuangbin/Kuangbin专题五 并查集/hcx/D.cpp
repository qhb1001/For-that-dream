#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=2e5+5;
int f[maxn],cnt[maxn];
int n,m;
void Init(){
    for(int i=0;i<=n;i++){
        f[i]=i;
        cnt[i]=0;
    }
}

int Find(int x){
    if(x!=f[x]){
        int t=f[x],y=Find(f[x]);
        cnt[x]+=cnt[t];
        f[x]=y;
    }
    return f[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>m){
        int ans=0;
        Init();
        for(int i=0;i<m;i++){
            int a,b,s;cin>>a>>b>>s;
            a--;
            int x=Find(a),y=Find(b);
            if(x!=y){
                f[y]=x;
                cnt[y]=s+cnt[a]-cnt[b];
            }
            else{
                if(s!=cnt[b]-cnt[a])
                    ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
