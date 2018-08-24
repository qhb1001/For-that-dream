#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2e4 + 5;
struct Edge1 {
    int x, y1, y2, type;
    Edge1(int a = 0, int b = 0, int c = 0, int d = 0): x(a), y1(b), y2(c), type(d) {}
    bool operator < (const Edge1 b) const {
        if (x != b.x)   return x < b.x;
        return type > b.type;
    }
};
struct Edge2 {
    int y, x1, x2, type;
    Edge2(int a = 0, int b = 0, int c = 0, int d = 0): y(a), x1(b), x2(c), type(d) {}
    bool operator < (const Edge2 b) const {
        if (y != b.y)   return y < b.y;
        return type > b.type;
    }
};
struct Node {
    int l, r, len, times, lazy;
}t[MAX<<2];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].len = t[i].times = t[i].lazy = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
}
void push(int i) {
    if (t[i].lazy) {
        t[i<<1].lazy += t[i].lazy;
        t[i<<1|1].lazy += t[i].lazy;
        t[i].lazy = 0;
    }
}
void up(int i) {
    if (t[i].times > 0) t[i].len = t[i].r - t[i].l;
    else    t[i].len = t[i<<1].len + t[i<<1|1].len;
    if (t[i<<1].times == t[i<<1|1].times)   t[i].times = t[i<<1].times;
    else    t[i].times = -1;
}
void update(int i, int l, int r, int type) {
    // cout << t[i].l << ' ' << t[i].r << ' ' << l << ' ' << r << endl;
    if (t[i].l == t[i].r) {
        t[i].times += type;
        if (t[i].times != 0)    t[i].len = 1;
        return ;
    }
    if (t[i].l == l && t[i].r == r && t[i].times != -1) {
        t[i].times += type;
        t[i].lazy += type;
        if (t[i].times == 0)    t[i].len = 0;
        else    t[i].len = t[i].r - t[i].l + 1;
        return ;
    }
    int mid = t[i].l + t[i].r >> 1;
    push(i);
    if (r <= mid) update(i<<1, l, r, type);
    else if (l > mid)   update(i<<1|1, l, r, type);
    else {
        update(i<<1, l, mid, type);
        update(i<<1|1, mid + 1, r, type);
    }
    up(i);
}
vector<Edge1>e1; vector<Edge2>e2;
int n, minX, minY, maxX, maxY;
void input() {
    int x1, x2, y1, y2;
    minX = 1<<30; minY = 1<<30;
    maxX = -(1<<30); maxY = -(1<<30);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        e1.push_back(Edge1(x1, y1, y2, 1));
        e1.push_back(Edge1(x2, y1, y2, -1));
        e2.push_back(Edge2(y1, x1, x2, 1));
        e2.push_back(Edge2(y2, x1, x2, -1));
        minX = min(minX, x1);
        minY = min(minY, y1);
        maxX = max(maxX, x2);
        maxY = max(maxY, y2);
    }
    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());
    n *= 2;
}
void deal() {
    int ans = 0, last = 0, now = 0;
    build(1, 0, maxX - minX);
    for (int i = 0; i < n; ++i) {
        // cout << e1[i].y1 - minY << ' ' << e1[i].y2 - minY << endl;
        update(1, e1[i].y1 - minY, e1[i].y2 - minY - 1, e1[i].type);
        last = now;
        now = t[1].len;
        ans += abs(now - last);
        cout << ans << endl;
    }

    cout << ans << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        input();
        deal();
    }
}