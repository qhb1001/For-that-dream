#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod = 1000;
ll pow_mod(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        int n, k;
        scanf("%d%d",&n,&k);
        double x = 1.0*k*log10(n*1.0);
        double ans = x - (ll)x;
        printf("Case %d: %lld %03lld\n",++kase, (ll)(pow(10,ans)*100),pow_mod(n,k));
    }
    return 0;
}

