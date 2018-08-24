#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 505;
struct Point {
    double x, y;
}p[MAX];
struct Edge {
    int u, v;
    double cost;
    Edge(int u_ = 0, int v_ = 0, double cost_ = 0): u(u_), v(v_), cost(cost_) {}
    bool operator < (const Edge b) const {
        return cost < b.cost;
    }
};
vector<Edge>e;
int n, s, fa[MAX], cnt[MAX];
double dis(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}
void input() {
    scanf("%d%d", &s, &n);
    e.clear();
    for (int i = 1; i <= n; ++i) fa[i] = i, cnt[i] = 1;
    for (int i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            e.push_back(Edge(i, j, dis(p[i], p[j])));
            e.push_back(Edge(j, i, dis(p[i], p[j])));
        }
    }
}
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
bool unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v]; fa[v] = u;
    return true;
}
bool cmp(double a, double b) {
    return a > b;
}
double deal() {
    int now = n, len = e.size();
    sort(e.begin(), e.end());
    vector<double>ans;
    for (int i = 0; i < len; ++i) {
        if (unit(e[i].u, e[i].v)) {
            --now;
            ans.push_back(e[i].cost);
            if (now == 1)   break;
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < n; ++i) {
        s--;
        if (s == 0) return ans[i];
    }
    return 0;
}
int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        input();
        printf("%.2lf\n", deal());
    }
}