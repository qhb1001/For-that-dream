#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
ll lazy[MAX], bit[MAX];
int in[MAX], out[MAX], cnt, n, q;
vector<int>large, flo[MAX], G[MAX];
void dfs(int u, int dep) {
    in[u] = ++cnt;
    flo[dep].push_back(cnt);
    for (int i: G[u]) dfs(i, dep + 1);
    out[u] = cnt;
}
inline int lowbit(int x) {return x & -x;}
void add(int i, int x) {
    for (; i <= n; i += lowbit(i))  bit[i] += x;
}
ll query(int i) {
    ll ans = 0;
    for (; i; i -= lowbit(i))   ans += bit[i];
    return ans;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1,  u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
    }
    
    dfs(1, 0);
    int sqrt_ = sqrt(n);
    for (int i = 0; i <= n; ++i) if (flo[i].size() > sqrt_)    large.push_back(i);
    
    int op, l, r;
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &l, &r);
            if (flo[l].size() <= sqrt_) {
                for (int i: flo[l]) add(i, r);
            }
            lazy[l] += r;
        } else {
            scanf("%d", &l);
            int x = in[l], y = out[l];
            long long ans = query(y) - query(x - 1);
            for (int i: large) {
                unsigned ll = lower_bound(flo[i].begin(), flo[i].end(), x) - flo[i].begin();
                auto rr = upper_bound(flo[i].begin(), flo[i].end(), y) - flo[i].begin();
                ans += (rr - ll) * lazy[i];
            }
            printf("%lld\n", ans);
        }
    }
}
