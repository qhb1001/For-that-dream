#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=3e4+10;
int dp[maxn][4];//从小到大
int dp2[maxn][4];//从大到小
int d[maxn];
int n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&d[i]);
    }

    for(int i=1;i<=n;i++){
        dp[i][1]=dp[i-1][1]+(d[i]==1?0:1);
        dp[i][2]=min(dp[i-1][1],dp[i-1][2])+(d[i]==2?0:1);
        dp[i][3]=min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3]))+(d[i]==3?0:1);
        // cout<<i<< " "<<dp[i][1]<< " "<<dp[i][2]<<" "<<dp[i][3]<<endl;
        dp2[i][3]=dp2[i-1][3]+(d[i]==3?0:1);
        dp2[i][2]=min(dp2[i-1][3],dp2[i-1][2])+(d[i]==2?0:1);
        dp2[i][1]=min(dp2[i-1][1],min(dp2[i-1][2],dp2[i-1][3]))+(d[i]==1?0:1);
        // cout<<i<< " "<<dp2[i][1]<< " "<<dp2[i][2]<<" "<<dp2[i][3]<<endl;
    }
    ans=min(dp[n][1],min(dp[n][2],dp[n][3]));
    ans=min(ans,min(dp2[n][1],min(dp2[n][2],dp2[n][3])));
    printf("%d\n",ans);
    return 0;
}