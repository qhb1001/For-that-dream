#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 5e4 + 5;
struct Node {
    int l, r, max_, min_;
}t[MAX<<2];
int a[MAX];
void up(int i) {
    t[i].max_ = max(t[i<<1].max_, t[i<<1|1].max_);
    t[i].min_ = min(t[i<<1].min_, t[i<<1|1].min_);
}
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; 
    if (l == r) {
        t[i].max_ = t[i].min_ = a[l];
        return ;
    }

    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    up(i);
}

int max__, min__;
void query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r) {
        max__ = max(max__, t[i].max_);
        min__ = min(min__, t[i].min_);
        return ;
    }

    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   query(i<<1, l, r);
    else if (l > mid)   query(i<<1|1, l, r);
    else {
        query(i<<1, l, mid);
        query(i<<1|1, mid + 1, r);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);

    int l, r;
    while (q--) {
        cin >> l >> r;
        max__ = -1;
        min__ = 1<<30;
        query(1, l, r);
        cout << max__ - min__ << '\n';
    }
} 