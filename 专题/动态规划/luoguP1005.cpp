//说好的unsigned longlong 128位呢！还是顺利的爆了，于是去写java了
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
const int maxn=100;
ll a[maxn];
ll dp[maxn];
ll two[maxn];
ll ans;
int n,m;
void init(){
    two[0]=1;
    for(int i=1;i<=80;i++){
        two[i]=two[i-1]*2;
    }
}

int main(){
    freopen("/Users/mrs_empress/Desktop/test/test/input", "r", stdin);
    ans=0;init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        for(int j=1;j<=m;j++){
            scanf("%llu",&a[j]);
        }
        for(int len=1;len<=m;len++){
            for(int j=1;j<=m;j++){
                if(j+len-1>m) break;
                dp[j]=max(dp[j+1]+a[j]*two[m-len+1],dp[j]+a[j+len-1]*two[m-len+1]);
            }
        }
        ans+=dp[1];
//        cout<<dp[1]<< " "<<ans<<endl;
    }
    printf("%llu\n",ans);
    return 0;
}
