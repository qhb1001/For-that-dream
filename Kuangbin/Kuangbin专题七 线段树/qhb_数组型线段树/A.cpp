#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 5e4 + 5;
struct Node {
    int sum, l, r;
}t[MAX<<2];
int n, a[MAX];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].sum = a[l];
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    t[i].sum = t[i<<1].sum + t[i<<1|1].sum;
}
int query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r) return t[i].sum;

    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(i<<1, l, r);
    else if (l > mid)   return query(i<<1|1, l, r);
    else    return query(i<<1, l, mid) + query(i<<1|1, mid + 1, r);
}
void update(int i, int l, int val) {
    if (t[i].l == t[i].r) {
        t[i].sum += val;
        return ;
    }

    int mid = t[i].l + t[i].r >> 1;
    if (l <= mid)   update(i<<1, l, val);
    else update(i<<1|1, l, val);

    t[i].sum = t[i<<1].sum + t[i<<1|1].sum;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string type;
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        cout << "Case " << k << ":\n";
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        build(1, 1, n);
        int l, r, val;
        while (cin >> type && type != "End") {
            if (type == "Query") {
                cin >> l >> r;
                cout << query(1, l, r) << '\n';
            } else if (type == "Add") {
                cin >> l >> val;
                update(1, l, val);
            } else {
                cin >> l >> val;
                update(1, l, -val);
            }
        }

    }
}