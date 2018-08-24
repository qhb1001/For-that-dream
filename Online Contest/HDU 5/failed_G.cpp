#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
unsigned int X, Y, Z, W;
unsigned int f() {
    X = X ^ (X << 11);
    X = X ^ (X >> 4);
    X = X ^ (X << 5);
    X = X ^ (X >> 14);

    W = X ^ (Y ^ Z);
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}

const int MAX = 1e5 + 5;
int fa[MAX], n, m;
void init() {
    for (int i = 1; i <= n + 1; ++i) {
        fa[i] = i;
    }
}
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    if (u == v) return ;
    fa[u] = v;
}
struct Node {
    unsigned int l, r, v;
    Node(unsigned int a = 0, unsigned int b = 0, unsigned int c = 0): l(a), r(b), v(c) {}
    bool operator < (const Node b) const {
        return v > b.v;
    }
}q[5000005];

unsigned int a[MAX];

struct TreeNode {
    int l, r;
    long long val;
    bool flag;
}t[MAX<<2];
void build(int idx, int l, int r) {
    t[idx].l = l;
    t[idx].r = r;
    t[idx].val = t[idx].flag = 0;
    if (l == r) return ;
    int mid = (l + r) >> 1;

    build(idx<<1, l, mid);
    build(idx<<1|1, mid + 1, r);
}
void update(int idx, int l, int r, long long val) {
    if (t[idx].flag == true)    return ;
    if (t[idx].l == l && t[idx].r == r) {
        t[idx].flag = true;
        t[idx].val = val;
        return ;
    }

    int mid = (t[idx].l + t[idx].r) >> 1;
    if (r <= mid)   update(idx<<1, l, r, val);
    else if (l > mid)   update(idx<<1|1, l, r, val);
    else {
        update(idx<<1, l, mid, val);
        update(idx<<1|1, mid + 1, r, val);
    }
}
long long query(int idx, int tofind) {
    if (t[idx].l == t[idx].r)   return t[idx].val;
    int mid = (t[idx].l + t[idx].r) >> 1;
    if (tofind <= mid)  return max(t[idx].val, query(idx<<1, tofind));
    else return max(t[idx].val, query(idx<<1|1, tofind));
}
int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    unsigned int l, r, v, f1, f2, f3;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%u%u%u", &n, &m, &X, &Y, &Z);
        init();
        // build(1, 1, n);
        // cout << X << ' ' << Y << ' ' << Z << endl;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; ++i) {
            f1 = f(); f2 = f(); f3 = f();
            l = min(f1 % n, f2 % n) + 1;
            r = max(f1 % n, f2 % n) + 1;
            v = f3 % (1<<30);
            q[i] = Node(l, r, v);
        }

        sort(q + 1, q + 1 + m);
        int cnt;
        for (int i = 1; i <= m; ++i) {
            l = q[i].l;
            r = q[i].r;
            v = q[i].v;
            // update(1, l, r, v);
            cnt = find(l);
            while (cnt <= r) {
                if (find(cnt) == cnt) {
                    a[cnt] = v;
                    unit(cnt, find(r + 1));
                    ++cnt;
                } else {
                    cnt = find(cnt);
                }
            }
            if (find(1) == n + 1)   break;
        }

        long long ans = 0;
        for (long long i = 1; i <= n; ++i) {
            ans ^= i * a[i];
        }
        printf("%lld\n", ans);
     }
}