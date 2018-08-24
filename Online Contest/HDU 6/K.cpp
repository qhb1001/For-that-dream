#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
const int MAX = 3e6 + 5;
int fac[MAX];
int extgcd(int a,int b,int &x,int &y){
    int d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else    x=1,y=0;
    return d;
}
int inv(int a){
    int x,y,d=extgcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}

int fun(int a,int b){
    if (b > a)  return 0;
    int x=inv((1LL*fac[b]*fac[a-b])%mod);
    return (1LL*fac[a]*x)%mod;
}
ll quick(ll a, ll b) {
    ll ans = 1, t = a % mod;
    for (; b; t = t * t % mod) {
        if (b&1)    ans = ans * t % mod;
        b >>= 1;
    }
    return ans;
}
void pretreatment() {
    fac[0] = 1;
    for (int i = 1; i < MAX; ++i) 
        fac[i] = 1LL * fac[i - 1] * i % mod;
}

int p[MAX], pr[MAX];
void init() {
    p[1]=1;
    int tot = 0;
    for (int i = 2; i <= 1500010; ++i) { // 其中N代表最大值
        if (!p[i]) p[i]=i,pr[++tot]=i;
        for (int j=1;j<=tot&&pr[j]*i<= 1500010;j++) {
            p[i*pr[j]]=pr[j];
            if (p[i]==pr[j]) break;
        }
    }
}

int main() {
    pretreatment();
    init();
    int T, c, k, n, pp;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &c, &n, &k);
        ll ans = 0, t;
        pp = pr[c];
        for (int j = 1; j <= k; ++j) {
            t = fun(j + pp, pp - 1);
            if (t < 0)   t += mod;
            // cout << t << endl;
            // cout << t * (1 - quick(t, n)) / (1 - t) << endl;
            if (t == 1) {
                ans = (ans + n) % mod;
            } else if (t > 0) {
                ans = (ans + (quick(t, n + 1) - t) * quick(t - 1, mod - 2) %mod) % mod;
            }
        }

        printf("%lld\n", (ans + mod) % mod);
    }
}