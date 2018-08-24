#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
    int l, r;
    long long lazy, sum;
}t[MAX<<2];
int a[MAX];
void up(int i) {//在使用的时候保证懒惰标记已经下传
    t[i].sum = t[i<<1].sum + t[i<<1|1].sum;
}
void push(int i) {
    if (t[i].lazy) {
        int len = t[i<<1].r - t[i<<1].l + 1;
        t[i<<1].lazy += t[i].lazy;
        t[i<<1].sum += len * t[i].lazy;
        len = t[i<<1|1].r - t[i<<1|1].l + 1;
        t[i<<1|1].lazy += t[i].lazy;
        t[i<<1|1].sum += len * t[i].lazy;
        t[i].lazy = 0;
    }
}
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; 
    if (l == r) {
        t[i].sum = a[l];
        return ;
    }

    int mid = t[i].l + t[i].r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    up(i);
}
void update(int i, int l, int r, long long val) {
    if (t[i].l == l && t[i].r == r) {
        t[i].lazy += val;
        t[i].sum += (r - l + 1) * val;
        return ;
    }

    push(i);
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   update(i<<1, l, r, val);
    else if (l > mid)   update(i<<1|1, l, r, val);
    else {
        update(i<<1, l, mid, val);
        update(i<<1|1, mid + 1, r, val);
    }
    up(i);
}
long long query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r)     return t[i].sum;

    push(i);
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(i<<1, l, r);
    else if (l > mid)   return query(i<<1|1, l, r);
    else {
        return query(i<<1, l, mid) + query(i<<1|1, mid + 1, r);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    // cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)  {
        // cin >> a[i];
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    char c[2];
    int l, r;
    long long val;
    while (m--) {
        scanf("%s", c);
        if (c[0] == 'Q') {
            // cin >> l >> r;
            scanf("%d%d", &l, &r);
            // cout << query(1, l, r) << '\n';
            printf("%lld\n", query(1, l, r));
        } else {
            // cin >> l >> r >> val;
            scanf("%d%d%lld", &l, &r, &val);
            update(1, l, r, val);
        }
    }
}