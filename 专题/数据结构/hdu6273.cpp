#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int MAX = 1e5 + 5;
int bit[2][MAX], n, q;
inline int lowbit(int x) {return x & (-x);}
void update(int ii, int i, int x) {
    for (; i <= n; i += lowbit(i)) bit[ii][i] += x;
}
int query(int ii, int i) {
    int ans = 0;
    for (; i; i -= lowbit(i)) ans += bit[ii][i];
    return ans;
}
ll Pow(ll a, int b, int p) {
    a%=p; ll ans=1;
    for(; b; b>>=1, a=a*a%p)
        if(b&1) ans=ans*a%p;
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q); memset(bit, 0, sizeof(bit));
        int l, r, val;
        while (q--) {
            scanf("%d%d%d", &l, &r, &val);
            if (val == 2)   update(0, l, 1), update(0, r + 1, -1);
            else update(1, l, 1), update(1, r + 1, -1);
        }

        int ans1 = 1<<30, ans2 = 1<<30;
        for (int i = 1; i <= n; ++i) ans1 = min(ans1, query(0, i)), ans2 = min(ans2, query(1, i));
        ll ans = (Pow(2, ans1, MOD) * Pow(3, ans2, MOD) % MOD + MOD ) % MOD;
        printf("%lld\n", ans);
    }
}