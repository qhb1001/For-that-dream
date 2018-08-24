#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
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
struct Node {
    int l, r;
    long long val, Min, lazy;
}t[MAX<<2];

void build(int i, int l, int r) {
    t[i].l = l;
    t[i].r = r;
    t[i].val = t[i].Min = t[i].lazy = 0;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
}
void push(int i) {
    if (t[i].lazy != 0) {
        t[i<<1].lazy = t[i<<1|1].lazy = t[i].lazy;
        t[i<<1].val = t[i<<1|1].val = t[i].lazy;
        t[i<<1].Min = t[i<<1|1].Min = t[i].lazy;
        t[i].lazy = 0;
    }
}
void up(int i) {
    t[i].val = max(t[i<<1].val, t[i<<1|1].val);
    t[i].Min = min(t[i<<1].Min, t[i<<1|1].Min);
}
void update(int i, int l, int r, long long val) {
    if (t[i].Min >= val)    return ;
    if (t[i].l == l && t[i].r == r) {
        if (t[i].val < val) {
            t[i].lazy = t[i].val = t[i].Min = val;
            return ; //如果放在外面一层就会WA，目前尚不清楚原因
        }
        //return ;
    } 
    
    int mid = (t[i].l + t[i].r) >> 1;
    push(i);
    if (r <= mid)   update(i<<1, l, r, val);
    else if (l > mid) update(i<<1|1, l, r, val);
    else {
        update(i<<1, l, mid, val);
        update(i<<1|1, mid + 1, r, val);
    }
    up(i);
}

long long a[MAX];
void query(int i) {
    if (t[i].val == t[i].Min) {
        for (int k = t[i].l; k <= t[i].r; ++k) {
            a[k] = t[i].val;
        }
        return ;
    }

    push(i);
    query(i<<1); query(i<<1|1);
}
int main() {
    // freopen("input.txt", "r", stdin);

    int T, n, m;
    scanf("%d", &T);
    unsigned int l, r, v, f1, f2, f3;
    while (T--) {
        scanf("%d%d%u%u%u", &n, &m, &X, &Y, &Z);
        build(1, 1, n);
        for (int i = 1; i <= m; ++i) {
            f1 = f(); f2 = f(); f3 = f();
            l = min(f1 % n, f2 % n) + 1;
            r = max(f1 % n, f2 % n) + 1;
            v = f3 % (1<<30);
            if (v == 0) continue;
            update(1, l, r, v);
        }

        long long ans = 0;
        query(1);
        for (int i = 1; i <= n; ++i) {
            ans ^= i * a[i];
        }

        printf("%lld\n", ans);
    }
}