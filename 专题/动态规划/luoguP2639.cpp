#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=46000;
int dp[maxn],c[maxn];
int n,m,ans;
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=c[i];j--){
            dp[j]=max(dp[j],dp[j-c[i]]+c[i]);
        }
    }
    
    for(int i=1;i<=m;i++){
        ans=max(ans,dp[i]);
    }
    printf("%d\n",ans);
    return 0;
}