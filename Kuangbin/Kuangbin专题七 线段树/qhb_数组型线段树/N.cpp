#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
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
    int l, r, len, times;
}t[MAX<<2];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].len = t[i].times = 0;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
}
void up(int i) {
    if (t[i].times) t[i].len = t[i].r - t[i].l + 1;
    else if (t[i].l == t[i].r)  t[i].len = 0;
    else t[i].len = t[i<<1].len + t[i<<1|1].len;
}
void update(int i, int l, int r, int val) {
    // cout << t[i].l << ' ' << t[i].r << ' ' << l << ' ' << r << endl;
    if (t[i].l == l && t[i].r == r) {
        t[i].times += val;
        up(i);
        return ;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   update(i<<1, l, r, val);
    else if (l > mid)   update(i<<1|1, l, r, val);
    else {
        update(i<<1, l, mid, val);
        update(i<<1|1, mid + 1, r, val);
    }
    up(i);
}
int n, minX, minY, maxX, maxY, ans;
vector<Edge1>e1;
vector<Edge2>e2;
void input() {
    e1.clear(); e2.clear();
    int x1, x2, y1, y2;
    minX = 1<<30; minY = 1<<30;
    maxX = -(1<<30); maxY = -(1<<30);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        // x1 += 10001; x2 += 10001; y1 += 10001; y2 += 10001;
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
    ans = 0;
    int last = 0, now = 0;
    build(1, 1, maxY - minY + 1);
    for (int i = 0; i < n; ++i) {
        update(1, e1[i].y1 - minY + 1, e1[i].y2 - minY, e1[i].type);
        last = now;
        now = t[1].len;
        ans += abs(now - last);
        // cout << now << endl;
    }

    last = 0; now = 0;
    build(1, 1, maxX - minX + 1);
    for (int i = 0; i < n; ++i) {
        update(1, e2[i].x1 - minX + 1, e2[i].x2 - minX, e2[i].type);
        last = now;
        now = t[1].len;
        ans += abs(now - last);

    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            printf("0\n");
            continue;
        }
        input();
        deal();
        printf("%d\n", ans);
    }
}