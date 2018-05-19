#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int JGJQ=678;//660+18
int dp[10000];//9000+678
int x,t,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,kase=1;
    //freopen("/Users/mrs_empress/Documents/算法/知识杂讲/【2】动态规划/DP紫书/DP紫书/input", "r", stdin);
    cin>>T;
    while(T--){
        cin>>n>>t;
        for(int i=0;i<10000;i++){
            dp[i]=-1;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++){
            cin>>x;
            for(int j=t-1;j>=x;j--){
                if(dp[j-x]!=-1){
                    dp[j]=max(dp[j],dp[j-x]+1);
                }
//                cout<<j<<" "<<j-x<<" "<<dp[j]<<endl;
            }
        }
        int ans=t-1;
        for(int i=t-1;i>=0;i--){
//            cout<<i<<" "<<dp[i]<<endl;
            if(dp[i]>dp[ans])
                ans=i;
        }
        cout<<"Case "<<kase++<<": "<<dp[ans]+1<<" "<<ans+JGJQ<<endl;
    }
    return 0;
}

