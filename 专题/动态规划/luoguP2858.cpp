#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=2010;
ll dp[maxn],v[maxn];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&v[i]);
        dp[i]=v[i]*n;
    }
    
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n;i++){
            if(i+len-1>n) continue;
            dp[i]=max(dp[i]+v[i+len-1]*(n-len+1),dp[i+1]+v[i]*(n-len+1));
        }
    }

    printf("%lld\n",dp[1]);
    return 0;
}