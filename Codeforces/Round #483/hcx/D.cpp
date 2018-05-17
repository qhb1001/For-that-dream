#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
ll dp[maxn][maxn],f[maxn][maxn],a[maxn];
bool vis[maxn][maxn];

void dfs(int l,int r){
    if(l==r){
        dp[l][l]=f[l][l]=a[l];
        return ;
    }
    
    if(!vis[l+1][r]){
        vis[l+1][r]=1;
        dfs(l+1,r);
    }
    if(!vis[l][r-1]){
        vis[l][r-1]=1;
        dfs(l,r-1);
    }
    f[l][r]=f[l+1][r]^f[l][r-1];
    dp[l][r]=max(f[l][r],max(dp[l+1][r],dp[l][r-1]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,n);
    int q;cin>>q;
    int l,r;
    while(q--){
        cin>>l>>r;
        cout<<dp[l][r]<<endl;
    }
    return 0;
}
