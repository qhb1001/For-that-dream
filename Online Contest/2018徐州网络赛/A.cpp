#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll Pow(ll a, int b, int p) {
    a%=p; ll ans=1;
    for(; b; b>>=1, a=a*a%p)
        if(b&1) ans=ans*a%p;
    return ans;
}
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, k; scanf("%d%d", &n, &k);
        ll base = Pow(2, k, MOD);
        ll ans = base * Pow(base - 1, n - 3, MOD) % MOD;
        ans = ((ans * ((base - 2) % MOD * (base - 2) % MOD + base - 1)) % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }
}