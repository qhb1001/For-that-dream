#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=3005;
const ll INF=1e9;
ll dp[maxn][4];
ll s[maxn],c[maxn];
int n;
ll ans=INF;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++) cin>>c[i];

    for(int i=0;i<n;i++){
        dp[i][0]=0;
        dp[i][1]=c[i];
        dp[i][2]=dp[i][3]=INF;
    }

    for(int i=1;i<n;i++){
        for(int j=2;j<=3;j++){
            for(int k=0;k<i;k++){
                if(s[k]>=s[i]) continue;
                dp[i][j]=min(dp[i][j],dp[k][j-1]+c[i]);
//                cout<<k<<" "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
//        cout<<i<<" "<<dp[i][3]<<endl;
        ans=min(ans,dp[i][3]);
    }

    if(ans==INF){
        cout<<-1<<endl;
    }
    else cout<<ans<<endl;
    return 0;
}
