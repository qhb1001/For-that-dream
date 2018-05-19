#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;;
const int INF=0x3f3f3f3f;
int a[15][105];
int dp[15][105];
int rows[3];
int nex[15][105];
int n,m;
int main(){
//    freopen("/Users/mrs_empress/Documents/算法/知识杂讲/【2】动态规划/DP紫书/DP紫书/input","r",stdin);
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        
        int ans=INF,first=0;
        if(n==1){
            for(int i=1;i<=m;i++){
                if(a[i][n]<ans){
                    ans=a[i][n];
                    first=i;
                }
            }
            cout<<first<<endl<<ans<<endl;
            continue;
        }
        for(int i=1;i<=m;i++){
            dp[i][n]=a[i][n];
        }
        
        for(int j=n-1;j>=1;j--){
            for(int i=1;i<=m;i++){
//                cout<<i<<" "<<j<<endl;
                rows[0]=i;
                rows[1]=(i+1<=m?i+1:1);
                rows[2]=(i-1>0?i-1:m);
                sort(rows,rows+3);
                dp[i][j]=INF;
                for(int k=0;k<3;k++){
                    int v=dp[rows[k]][j+1]+a[i][j];
                    if(v<dp[i][j]){
                        dp[i][j]=v;
                        nex[i][j]=rows[k];
                    }
                }
//                cout<<dp[i][j]<<" "<<nex[i][j]<<endl;
                if(j==1&&dp[i][j]<ans){
//                    cout<<ans<<" "<<dp[i][j]<<" "<<i<<endl;
                    ans=dp[i][j];
                    first=i;
                }
            }
        }
        
        printf("%d",first);
        for(int i=nex[first][1],j=2;j<=n;i=nex[i][j],j++){
            printf(" %d",i);
        }
        printf("\n%d\n",ans);
    }
    return 0;
}
