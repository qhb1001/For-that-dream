#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1005;
struct ty{
    int v,k,c,l;
}Light[maxn];
int sum[maxn],dp[maxn];
int n;
bool cmp(ty a,ty b){
    return a.v<b.v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        if(!n) break;
        for(int i=1;i<=n;i++){
            cin>>Light[i].v>>Light[i].k>>Light[i].c>>Light[i].l;
        }
        sort(Light+1,Light+1+n,cmp);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+Light[i].l;
        }
        
        for(int i=1;i<=n;i++){
            dp[i]=Light[i].k+Light[i].c*sum[i];
            for(int j=1;j<i;j++){
                dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j])*Light[i].c+Light[i].k);
            }
        }
        cout<<dp[n]<<endl;
    }
}
