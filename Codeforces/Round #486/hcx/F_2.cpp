#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=2e3+10;
const int INF=0x3f3f3f3f;
int a,m,n;
int rain[maxn],um[maxn];
int dp[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>n>>m;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        for(int j=x;j<y;j++) rain[j]=1;
    }

    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        if(!um[x]) um[x]=y;
        else um[x]=min(um[x],y);
    }

    memset(dp,INF,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=a;i++){
        if(rain[i-1]){
            for(int j=i-1;j>=0;j--){
                if(um[j]) dp[i]=min(dp[i],dp[j]+um[j]*(i-j));
            }
        }else{
            dp[i]=dp[i-1];
        }
    }
    if(dp[a]==INF){
        cout<<-1<<endl;
    }
    else cout<<dp[a]<<endl;
    return 0;
}

