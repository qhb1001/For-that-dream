#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans = 0;
        int m = sqrt(n);
        for(int i=1; i<m; i++){
            ans += n/i;
            ans += (ll)i*(n/i -n/(i+1));
        }
        ans += n/m;
        ans += m*(n/m-m);
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
