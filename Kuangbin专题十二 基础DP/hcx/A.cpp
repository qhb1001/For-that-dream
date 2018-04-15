#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int INF=0x3f3f3f;
ll dp[maxn][2];
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=0;i<=m;i++)
            dp[i][0]=dp[i][1]=-INF;
        ll x;
        scanf("%lld",&x);
        dp[1][1]=dp[1][0]=x;

        for(int j=2;j<=n;j++){
            scanf("%lld",&x);
            for(int k=min(m,j);k>=2;k--){
                ll y=dp[k][1];
                dp[k][1]=max(dp[k-1][0],dp[k-1][1])+x;
                if(k<=j-1){
                    dp[k][0]=max(dp[k][0],y);
                    dp[k][1]=max(dp[k][1],y+x);
                }
//                cout<<j<<" "<<k<<" "<<dp[k][0]<<" "<<dp[k][1]<<endl;
            }
            dp[1][0]=max(dp[1][0],dp[1][1]);
            dp[1][1]=max(x,dp[1][1]+x);
//            cout<<j<<" "<<1<<" "<<dp[1][0]<<" "<<dp[1][1]<<endl;
        }
        ll ans=0;
        ans=max(dp[m][0],dp[m][1]);
        cout<<ans<<endl;
    }
    return 0;
}
