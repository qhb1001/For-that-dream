#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2005;
const int INF=1e5+5;
int dp[maxn][2];
int a[maxn],b[maxn];
void outputs(int x){
    int h=8,m=0,s=0;
    s=x;
    m=s/60;s=s%60;
    h+=m/60;m=m%60;
    h=h%24;
    if(h>=12){
        h-=12;
        printf("%02d:%02d:%02d pm\n",h,m,s);
    }
    else{
        printf("%02d:%02d:%02d am\n",h,m,s);
    }
}
int main(){
    int n,k;scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        for(int i=2;i<=k;i++){
            scanf("%d",&b[i]);
        }
        dp[0][1]=0;
        dp[0][0]=0;
        dp[1][1]=a[1];
        dp[1][0]=INF;
        for(int i=2;i<=k;i++){
            dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a[i];
            dp[i][0]=min(dp[i-2][0],dp[i-2][1])+b[i];
        }
        outputs(min(dp[k][0],dp[k][1]));
    }
    return 0;
}
