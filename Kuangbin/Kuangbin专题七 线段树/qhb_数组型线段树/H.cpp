#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 6;
typedef long long ll;
struct Node {
    int l, r;
    ll val;
}t[MAX<<4];
ll a[MAX];
void up(int i) {
    t[i].val = t[i<<1].val + t[i<<1|1].val;
}
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; 
    if (l == r) {
        t[i].val = a[l];
        return ;
    }

    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    up(i);
}
void update(int i, int l, int r) {
    // cout << t[i].l << ' ' << t[i].r << ' ' << l << ' ' << r << ' ' << t[i].val << endl;
    if (t[i].r - t[i].l + 1 == t[i].val) return ;

    if (t[i].l == t[i].r) {
        t[i].val = (ll)(sqrt(t[i].val * 1.0));
        return ;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   update(i<<1, l, r);
    else if (l > mid)   update(i<<1|1, l, r);
    else {
        update(i<<1, l, mid);
        update(i<<1|1, mid + 1, r);
    }
    up(i);
}
ll query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r) return t[i].val;

    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(i<<1, l, r);
    else if (l > mid)   return query(i<<1|1, l, r);
    else {
        return query(i<<1, l, mid) + query(i<<1|1, mid + 1, r);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, k = 1;
    while (cin >> n) {
        cout << "Case #" << k++ << ":\n";
        for (int i = 1; i <= n; ++i)    cin >> a[i];
        build(1, 1, n);
        cin >> q;
        int type, l, r;
        while (q--) {
            cin >> type >> l >> r;
            if (l > r)  swap(l , r);
            if (type == 0) {
                update(1, l, r);
                // traverse(1);
                // cout << endl;
            }
            else cout << query(1, l, r) << '\n';
        }
        cout << '\n';
    }
}