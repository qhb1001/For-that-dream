#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
struct Point {
    bool type;//represent l-value or r-value
    int val, id;
    bool operator < (const Point b) const {
        return val < b.val;
    }
}p[MAX<<1];
int len[2][MAX], n, cnt;
void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i*2-1].val >> p[i*2].val;
        p[i*2-1].type = 0;p[i*2].type = 1;
        p[i*2-1].id = p[i*2].id = i;
    }
    cnt = 1;
    sort(p + 1, p + 1 + 2*n);
    len[p[1].type][p[1].id] = 1;
    for (int i = 2; i <= 2*n; ++i) {
        if (p[i].val == p[i - 1].val) {
            len[p[i].type][p[i].id] = cnt;
        } else {
            len[p[i].type][p[i].id] = ++cnt;
        }
    }
}

struct Node {
    int l, r, color, lazy;
}t[MAX<<3];//注意此处应该开多大的空间
//经过检验，应该开出四倍于最大容量的空间，才最保险
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].color = 0; t[i].lazy = 0;
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
        t[i<<1].color = t[i<<1|1].color = t[i<<1|1].lazy = t[i<<1].lazy = t[i].lazy;
        t[i].lazy = 0;
    }
}
void update(int i, int l, int r, int color) {
    if (t[i].l == l && t[i].r == r) {
        t[i].color = t[i].lazy = color;
        return ;
    }

    int mid = t[i].l + t[i].r >> 1;
    push(i);
    if (r <= mid)   update(i<<1, l, r, color);
    else if (l > mid)   update(i<<1|1, l, r, color);
    else {
        update(i<<1, l, mid, color);
        update(i<<1|1, mid + 1, r, color);
    }
    up(i);
} 

bool vis[MAX];
void query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r && t[i].color != -1) {
        vis[t[i].color] = 1;
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
    int t;
    for (cin >> t; t; --t) {
        input();
        build(1, 1, cnt);

        for (int i = 1; i <= n; ++i) update(1, len[0][i], len[1][i], i);

        memset(vis, 0, sizeof(vis));
        query(1, 1, cnt);

        int ans = 0;
        for (int i = 1; i <= n; ++i)    ans += vis[i];

        cout << ans << endl;
        
        
        // for (int i = 1; i <= n; ++i) {
        //     cout << len[0][i] << ' ' << len[1][i] << endl;
        // }
    }
}