#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int vis[maxn];
int n,k,r,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>r;
    for(int i=1;i<=k;i++){
        cin>>x;vis[x]=1;
    }

    int ans=0,cnt=0;
    for(int i=1;i<=r;i++){
        if(vis[i]) cnt++;
    }
    if(cnt<2) ans+=2-cnt;

    for(int i=r;i>=1;i--){
        if(cnt==2) break;
        if(!vis[i]){
            vis[i]=1;
            cnt++;
        }
    }

    for(int i=r+1;i<=n;i++){
        cnt=cnt-vis[i-r]+vis[i];
        if(cnt<2){
            vis[i]=1;
            ans++;
            cnt=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
