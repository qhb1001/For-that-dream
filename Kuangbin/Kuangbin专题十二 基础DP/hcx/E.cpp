#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int a[1005];
int dp[1005];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(!n) break;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        a[0]=0;
        dp[0]=0;
        int v;
        for(int i=1;i<=n;i++){
            v=-1;
            for(int j=0;j<i;j++){
                if(v<dp[j]&&a[j]<a[i]){
                    v=dp[j];
                }
            }
            dp[i]=v+a[i];
        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

