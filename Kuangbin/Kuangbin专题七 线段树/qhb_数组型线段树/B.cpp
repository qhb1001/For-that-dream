#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e5 + 5;
struct Node {
    int val, l, r;
}t[MAX<<2];
int a[MAX];
void up(int i) {
    t[i].val = max(t[i<<1].val, t[i<<1|1].val);
}
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].val = a[l];
    if (l == r) return ;

    int mid = l + r >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
    up(i);
}
void update(int i, int l, int val) {
    if (t[i].l == t[i].r) {
        t[i].val = val;
        return ;
    }

    int mid = t[i].l + t[i].r >> 1;
    if (l <= mid)   update(i<<1, l, val);
    else    update(i<<1|1, l, val);
    up(i);
}
int query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r)     return t[i].val;
    
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(i<<1, l, r);
    else if (l > mid)   return query(i<<1|1, l, r);
    else {
        return max(query(i<<1, l, mid), query(i<<1|1, mid + 1, r));
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    while (cin >> n >> q) {
        for (int i = 1; i <= n; ++i)    cin >> a[i];
        build(1, 1, n);
        char c;
        int l, r, val;
        while (q--) {
            cin >> c;
            if (c == 'Q') {
                cin >> l >> r;
                cout << query(1, l, r) << '\n';
            } else {
                cin >> l >> val;
                update(1, l, val);
            }
        }
    }
}