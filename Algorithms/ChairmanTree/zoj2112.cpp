#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e4 + 5;
int root[MAX], L[MAX*200], R[MAX*200], num[MAX*200], cnt, a[MAX], b[MAX], n, m, len;
int q1[MAX], q2[MAX], t1, t2;
inline int lowbit(int x) {return x&-x;}
struct Query {
    char s[2];
    int l, r, val;
}q[10005];
void init() {
    memset(num, 0, sizeof(num));
    memset(L, 0, sizeof(L));
    memset(R, 0, sizeof(R));
    cnt = 0;
    len = 0;
}
void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[++len] = a[i];
    for (int i = 1; i <= m; ++i) {
        scanf("%s", q[i].s);
        if (q[i].s[0] == 'Q') scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].val);
        else scanf("%d%d", &q[i].l, &q[i].val), b[++len] = q[i].val;
    }
}
void discrete() {
    sort(b + 1, b + 1 + len);
    len = unique(b + 1, b + 1 + len) - b - 1;
}
int update(int i, int l, int r, int idx, int val) {
    int ii = ++cnt; L[ii] = L[i]; R[ii] = R[i]; num[ii] = num[i] + val; 
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = update(L[ii], l, mid, idx, val);
    else R[ii] = update(R[ii], mid + 1, r, idx, val);
    return ii;
}
void add(int t, int type) {
    int val = lower_bound(b + 1, b + 1 + len, a[t]) - b;
    for (; t <= n; t += lowbit(t))    root[t] = update(root[t], 1, len, val, type);
}
int cal() {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= t1; ++i)   sum1 += num[L[q1[i]]];
    for (int i = 1; i <= t2; ++i)   sum2 += num[L[q2[i]]];
    return sum2 - sum1;
}
int query(int l, int r, int k) {
    t1 = t2 = 0;
    for (int i = l - 1; i; i -= lowbit(i)) q1[++t1] = root[i];
    for (int i = r; i; i -= lowbit(i)) q2[++t2] = root[i];
    int mid, now;
    l = 1, r = len;
    while (l < r) {
        now = cal(); mid = l + r >> 1;
        if (k <= now)   {
            for (int i = 1; i <= t1; ++i)   q1[i] = L[q1[i]];
            for (int i = 1; i <= t2; ++i)   q2[i] = L[q2[i]];
            r = mid;
        } else {
            k -= now; l = mid + 1;
            for (int i = 1; i <= t1; ++i)   q1[i] = R[q1[i]];
            for (int i = 1; i <= t2; ++i)   q2[i] = R[q2[i]];
        }
    }
    return b[l];
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        input();
        discrete();
        for (int i = 1; i <= n; ++i) add(i, 1);

        for (int i = 1; i <= m; ++i) {
            if (q[i].s[0] == 'C') {
                add(q[i].l, -1);
                a[q[i].l] = q[i].val;
                add(q[i].l, 1);
            } else {
                printf("%d\n", query(q[i].l, q[i].r, q[i].val));
            }
        }
    }
}