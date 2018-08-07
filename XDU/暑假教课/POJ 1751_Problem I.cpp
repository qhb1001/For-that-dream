#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 800;
int fa[MAX], cnt[MAX];

int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}
struct Point {
    ll x, y;
}point[MAX];

struct Edge {
    int from, to;
    ll dis;
    Edge(int a = 0, int b = 0, ll c = 0): from(a), to(b), dis(c) {}
    bool operator < (const Edge b) const {
        return dis > b.dis;
    }
};
ll dis(Point a, Point b) {
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int n, m;
priority_queue<Edge>q;
void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &point[i].x, &point[i].y);
    }
    //initialization for union-find set
    for (int i = 1; i <= n; ++i) fa[i] = i, cnt[i] = 1;
    
    //initialization for the priority queue
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            q.push(Edge(i, j, dis(point[i], point[j])));
        }
    }

    scanf("%d", &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        if (find(u) != find(v))  unit(u, v), n--;
    }
}

vector<Edge>ans;
void deal() {
    Edge now;
    while (n != 1) {
        now = q.top(); q.pop();
        if (find(now.from) == find(now.to)) continue;
        n--;
        unit(now.from, now.to);
        ans.push_back(Edge(now.from, now.to));
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    input();
    deal();
    int len = ans.size();
    for (int i = 0; i < len; ++i) {
        printf("%d %d\n", ans[i].from, ans[i].to);
    }
}