#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
    int l, r, color, lazy;
}t[MAX<<2];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].color = 1; t[i].lazy = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
}

void up(int i) {
    if (t[i<<1].color == t[i<<1|1].color)   t[i].color = t[i<<1].color;
    else    t[i].color = -1;
}
void push(int i) {
    if (t[i].lazy) {
        t[i<<1].color = t[i<<1].lazy = t[i<<1|1].color = t[i<<1|1].lazy = t[i].color;
        t[i].lazy = 0;
    }
}
void update(int i, int l, int r, int color) {
    if (t[i].l == l && t[i].r == r) {
        t[i].color = t[i].lazy = color;
        return ;
    }

    push(i);
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   update(i<<1, l, r, color);
    else if (l > mid)   update(i<<1|1, l, r, color);
    else {
        update(i<<1, l, mid, color);
        update(i<<1|1, mid + 1, r, color);
    }
    up(i);
}
int ans;
void query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r && t[i].color != -1) {
        ans += t[i].color * (t[i].r - t[i].l + 1);
        return ;
    }

    push(i);
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

    int t; scanf("%d", &t);
    for (int k = 1; k <= t; ++k) {
        int n, q, l, r, val;
        scanf("%d%d", &n, &q);
        build(1, 1, n);
        while (q--) {
            scanf("%d%d%d", &l, &r, &val);
            update(1, l, r, val);
        }
        ans = 0;
        query(1, 1, n);
        // cout << "Case " << k << ": The total value of the hook is " << ans << ".\n";
        printf("Case %d: The total value of the hook is %d.\n", k, ans);
    }
 
 }