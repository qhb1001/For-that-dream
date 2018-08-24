#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
    int l, r, times;
    double len;
}t[MAX<<3];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].len = t[i].times = 0;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
}
struct Edge {
    double x, y1, y2;
    int val;
    Edge(double _1 = 0, double _2 = 0, double _3 = 0, int _4 = 0): x(_1), y1(_2), y2(_3), val(_4) {}
    bool operator < (const Edge b) const {
        if (x != b.x)   return x < b.x;
        return val > b.val;
    }
};
vector<Edge>e;
map<double, int>mp;
vector<double>temp;
int Max;
double a[MAX];
void preTreatment() {
    sort(temp.begin(), temp.end());
    mp[temp[0]] = 1;
    a[1] = temp[0];
    int len = temp.size(), cnt = 1;
    for (int i = 1; i < len; ++i) {
        if (temp[i] == temp[i - 1]) continue;
        else    mp[temp[i]] = ++cnt, a[cnt] = temp[i];
    }
    Max = cnt;
}
void up(int i) {
    if (t[i].times) t[i].len = a[t[i].r + 1] - a[t[i].l];
    else if (t[i].l == t[i].r)  t[i].len = 0;
    else    t[i].len = t[i<<1].len + t[i<<1|1].len;
}
void update(int i, int l, int r, int val) {
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

int main() {
    // freopen("input.txt", "r", stdin);
    int n, cnt = 1;
    while (scanf("%d", &n) && n) {
        double x1, x2, y1, y2;
        e.clear(); temp.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            temp.push_back(y1); temp.push_back(y2);
            e.push_back(Edge(x1, y1, y2, 1));
            e.push_back(Edge(x2, y1, y2, -1));
        }
        sort(e.begin(), e.end());
        preTreatment();
        build(1, 1, Max + 1);
        double ans = 0, now = 0, x;
        for (int i = 0; i < 2*n; ++i) {
            ans += now * (e[i].x - x);
            // cout << mp[e[i].y1] << ' ' << mp[e[i].y2] << endl;
            update(1, mp[e[i].y1], mp[e[i].y2] - 1, e[i].val);
            now = t[1].len;
            x = e[i].x;
            // cout << now << endl;

        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", cnt++, ans);
    }
}