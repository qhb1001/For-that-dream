#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+5;
int dp[2][11];
int xb[11][maxn+10];
bool flag;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(!n) break;
        memset(dp, 0, sizeof(dp));
        memset(xb,0,sizeof(xb));
        flag=false;
        int T=0;
        for(int i=1;i<=n;i++){
            int x,t;
            scanf("%d%d",&x,&t);
            T=max(T,t);
            xb[x][t]++;
        }

        for(int i=1;i<=T;i++){
            flag=!flag;
            for(int j=0;j<=10;j++){
                if(i<5){
                    if(abs(j-5)>i)continue;
                }
                if(j!=0)
                    dp[flag][j]=max(dp[flag][j],dp[!flag][j-1]+xb[j][i]);
                if(j!=10)
                    dp[flag][j]=max(dp[flag][j],dp[!flag][j+1]+xb[j][i]);
                dp[flag][j]=max(dp[flag][j],dp[!flag][j]+xb[j][i]);
            }
        }
        int ans=0;
        for(int i=0;i<=10;i++){
            ans=max(ans,dp[flag][i]);
        }
        cout<<ans<<endl;
    }
}
