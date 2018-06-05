#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=2e3+10;
const int INF=0x3f3f3f3f;
int rain[maxn],f[maxn],um[maxn];
int dp[maxn][maxn];
int a,n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        rain[x+1]++;
        rain[y+1]--;
    }

    for(int i=1;i<=a;i++) rain[i]+=rain[i-1];
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        um[i]=y;
        if(f[x]==0) f[x]=i;
        else{
            int j=f[x];
            if(um[j]>um[i]) f[x]=i;
        }
    }

    memset(dp,INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<=m;j++){
            if(dp[i][j]!=INF){
                if(j==0){//now don't have um
                    if(f[i]!=0){//take
                        dp[i+1][f[i]]=min(dp[i+1][f[i]],dp[i][j]+um[f[i]]);
                    }
                    if(rain[i+1]==0)//don't take
                        dp[i+1][0]=min(dp[i+1][0],dp[i][j]);
                }
                else{
                    if(f[i]!=0){//change
                        dp[i+1][f[i]]=min(dp[i+1][f[i]],dp[i][j]+um[f[i]]);
                    }
                    //keep
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+um[j]);
                    if(rain[i+1]==0)//don't take
                        dp[i+1][0]=min(dp[i+1][0],dp[i][j]);
                }
            }
        }
    }
    int ans=INF;
    for(int i=0;i<=m;i++){
        ans=min(ans,dp[a][i]);
    }
    if(ans>=INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
