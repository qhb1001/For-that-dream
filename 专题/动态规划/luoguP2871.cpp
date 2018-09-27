#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=15000;
int dp[maxn],c[maxn],w[maxn];
int n,m,ans;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&w[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        }
    }
    
    for(int i=1;i<=m;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}