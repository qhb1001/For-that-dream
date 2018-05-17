#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int dp[55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;cin>>s;
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=max(dp[i],1);
        for(int j=i+1;j<n;j++){
            if(s[j]>s[i]) dp[j]=max(dp[i]+1,dp[j]);
        }
        ans=max(ans,dp[i]);
    }
    cout<<26-ans<<endl;
    return 0;
}
