#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 2e5 + 5;
int sum[MAX<<5], L[MAX<<5], R[MAX<<5], root[MAX], cnt, a[MAX], b[MAX];
//build an empty tree
void build(int &i, int l, int r) {
    i = ++cnt; sum[i] = 0;
    if (l == r) return ;
    int mid = l +r >> 1;
    build(L[i], l, mid); build(R[i], mid + 1, r);
}

//create the new node while traverse the tree
int modify(int i, int l, int r, int idx) {
    int ii = ++cnt;
    L[ii] = L[i]; R[ii] = R[i]; sum[ii] = sum[i] + 1;
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = modify(L[ii], l, mid, idx);
    else R[ii] = modify(R[ii], mid + 1, r, idx);
    return ii;
}

//find the exact location of the k-th minimum value in [l, r]
int query(int u, int v, int l, int r, int k) {
    int x = sum[L[v]] - sum[L[u]];
    if (l == r) return l;
    int mid = l + r >> 1;
    if (k <= x) return query(L[u], L[v], l, mid, k);
    else    return query(R[u], R[v], mid + 1, r, k - x);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)    scanf("%d", &b[i]), a[i] = b[i];
    sort(b + 1, b + 1 + n);
    int len = unique(b + 1, b + 1 + n) - b - 1;
    build(root[0], 1, len);
    
    int val;
    for (int i = 1; i <= n; ++i) {
        val = lower_bound(b + 1, b + 1 + len, a[i]) - b;
        root[i] = modify(root[i - 1], 1, len, val);
    }

    int l, r, k;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", b[query(root[l - 1], root[r], 1, len, k)]);
    }
}