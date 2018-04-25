#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=105;
int dp[maxn][maxn];
int a[maxn][maxn];
int main(){
    int c,m;
    freopen("/Users/mrs_empress/Desktop/data_2016/selling/data/secret/random1019.in", "r", stdin);
    while(scanf("%d%d",&c,&m)!=EOF){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=c;j++){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=c;j++){
                for(int k=0;k<=j;k++){
                    dp[i][j]=max(dp[i-1][j-k]+a[i][k],dp[i][j]);
                }
            }
        }
        int ans=0;
        for(int j=1;j<=c;j++){
            ans=max(ans,dp[m][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
