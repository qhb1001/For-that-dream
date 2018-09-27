#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int root[MAX], L[MAX<<5], R[MAX<<5], cnt, sum[MAX<<5], a[MAX], b[MAX];
void build(int &i, int l, int r) {
    i = ++cnt;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(L[i], l, mid); build(R[i], mid + 1, r);
}
int update(int i, int l, int r, int idx) {
    int ii = ++cnt;
    L[ii] = L[i]; R[ii] = R[i]; sum[ii] = sum[i] + 1;
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = update(L[ii], l, mid, idx);
    else    R[ii] = update(R[ii], mid + 1, r, idx);
    return ii;
}
int query(int u, int v, int l, int r, int k) {
    int x = sum[L[v]] - sum[L[u]];
    if (l == r) return l;
    int mid = l + r >> 1;
    if (k <= x) return query(L[u], L[v], l, mid, k);
    else return query(R[u], R[v], mid + 1, r, k - x);
}

int main() {
    int n, m, t;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    build(root[0], 1, n);
    for (int i = 1; i <= n; ++i) {
        t = lower_bound(b + 1, b + 1 + n, a[i]) - b;
        root[i] = update(root[i - 1], 1, n, t);
    }
    
    int l, r, k;
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", b[query(root[l - 1], root[r], 1, n, k)]);
    }
}