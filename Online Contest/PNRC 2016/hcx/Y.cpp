#include <iostream>
#include <cstdio>
using namespace std;
int dp[55][2];
int a[55];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1][0]=1;dp[1][1]=1;
    for(int i=2;i<=n;i++){
        int maxx0=0,maxx1=0;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]) maxx0=max(maxx0,dp[j][0]);
            else if(a[j]>a[i]) maxx1=max(maxx1,dp[j][1]);
        }
        dp[i][0]=maxx1+1;
        dp[i][1]=maxx0+1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
    }
    cout<<ans<<endl;
    return 0;
}
