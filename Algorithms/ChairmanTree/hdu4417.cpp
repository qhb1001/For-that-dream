#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int root[MAX], L[MAX<<5], R[MAX<<5], sum[MAX<<5], cnt, a[MAX], b[MAX];
void build(int &i, int l, int r) {
    i = ++cnt; sum[i] = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(L[i], l, mid);
    build(R[i], mid + 1, r);
}
int update(int i, int l, int r, int idx) {
    int ii = ++cnt;
    L[ii] = L[i]; R[ii] = R[i]; sum[ii] = sum[i] + 1;
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = update(L[ii], l, mid, idx);
    else R[ii] = update(R[ii], mid + 1, r, idx);
    return ii;
}
int query(int u, int v, int l, int r, int k) {
    int x = sum[L[v]] - sum[L[u]];
    if (l == r) return sum[v] - sum[u];
    int mid = l + r >> 1;
    if (k <= mid) return query(L[u], L[v], l, mid, k);
    else return x + query(R[u], R[v], mid + 1, r, k);
}

int main() {
    int T, n, m, len, t, kase = 1, l, r, k, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)    scanf("%d", &a[i]), b[i] = a[i];
        sort(b + 1, b + 1 + n);
        len = unique(b + 1, b + 1 + n) - b - 1;
        cnt = 0;
        build(root[0], 1, len);
        for (int i = 1; i <= n; ++i) {
            t = lower_bound(b + 1, b + 1 + len, a[i]) - b;
            root[i] = update(root[i - 1], 1, len, t);
        }
        printf("Case %d:\n", kase++);
        while (m--) {
            scanf("%d%d%d", &l, &r, &k); ++l; ++r;
            t = lower_bound(b + 1, b + 1 + len, k) - b;
            if (t == len + 1)  ans = r - l + 1;
            else if (t == 1 && b[1] != k)   ans = 0;
            else {
                if (b[t] != k) --t;
                ans = query(root[l - 1], root[r], 1, len, t);
            }
            
            printf("%d\n", ans);
        }
    }
}