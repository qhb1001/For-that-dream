//刚开始把m理解错了，不过状态设计对了哦！
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=2510;
ll dp[maxn],a[maxn];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    a[0]=m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    if(n==0){
        printf("0\n");
        return 0;
    }

    dp[0]=0;
    for(int i=1;i<=n-1;i++){
        dp[i]=dp[i-1]+a[1]+a[0];
        for(int x=2;x<=i;x++){
            dp[i]=min(dp[i-x]+a[x]+a[0],dp[i]);
        }
    }
    dp[n]=dp[n-1]+a[1];
    for(int x=1;x<=n;x++){
        dp[n]=min(dp[n],dp[n-x]+a[x]);
    }
    printf("%lld\n",dp[n]);
    return 0;
}