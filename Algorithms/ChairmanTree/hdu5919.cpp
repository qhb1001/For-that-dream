#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 2e5 + 5;
int root[MAX], L[MAX*40], R[MAX*40], num[MAX*40], cnt, a[MAX], last[MAX];
void build(int &i, int l, int r) {
    i = ++cnt; num[i] = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(L[i], l, mid); build(R[i], mid + 1, r);
}
int update(int i, int l, int r, int idx, int val) {
    int ii = ++cnt; L[ii] = L[i]; R[ii] = R[i]; num[ii] = num[i] + val;
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = update(L[ii], l, mid, idx, val);
    else    R[ii] = update(R[ii], mid + 1, r, idx, val);
    return ii;
}
int queryForSum(int i, int l, int r, int ll, int rr) {
    if (ll == l && rr == r)    return num[i];
    int mid = l + r >> 1;
    if (rr <= mid)  return queryForSum(L[i], l, mid, ll, rr);
    else if (ll > mid)  return queryForSum(R[i], mid + 1, r, ll ,rr);
    else return queryForSum(L[i], l, mid, ll, mid) + queryForSum(R[i], mid + 1, r, mid + 1, rr);
}
int queryForAns(int i, int l, int r, int k) {
    int mid = l + r >> 1;
    if (l == r) return l;
    if (k <= num[L[i]]) return queryForAns(L[i], l, mid, k);
    else return queryForAns(R[i], mid + 1, r, k - num[L[i]]);
}
int main() {
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        cnt = 0;
        printf("Case #%d:", kase);
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)    scanf("%d", &a[i]);
        memset(last, 0, sizeof(last));
        build(root[n + 1], 1, n);
        for (int i = n; i >= 1; --i) {
            if (!last[a[i]]) root[i] = update(root[i + 1], 1, n, i, 1);
            else {
                root[i] = update(root[i + 1], 1, n, last[a[i]], -1);
                root[i] = update(root[i], 1, n, i, 1);
            }
            last[a[i]] = i;
        }

        int ll, rr, ans = 0, l, r, k;
        while (m--) {
            scanf("%d%d", &ll, &rr);
            l = min((ll + ans) % n + 1, (rr + ans) % n + 1);
            r = max((ll + ans) % n + 1, (rr + ans) % n + 1);
            k = queryForSum(root[l], 1, n, l, r);
            k = (k + 1) / 2;
            ans = queryForAns(root[l], 1, n, k);
            printf(" %d", ans);
        }
        printf("\n");
    }
    return 0;
}