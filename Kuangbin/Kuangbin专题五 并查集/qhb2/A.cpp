#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;
const int MAX = 1005;
bool ok[MAX];
int fa[MAX], cnt[MAX];
void init() {
    for (int i = 1; i <= 1000; ++i)
    fa[i] = i, cnt[i] = 1;
}

int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return ;

    if (cnt[u] < cnt[v])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}

int n;
double d;
struct Point {
    double x, y;
    bool check(Point b) {
        double dx = x - b.x;
        double dy = y - b.y;
        if (dx * dx + dy * dy <= d * d) return true;
        return false;
    }
}point[MAX];
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    init();

    char c;
    int u, v;
    while (cin >> c) {
        if (c == 'O') {
            cin >> u;
            if (ok[u])  continue;
            ok[u] = 1;

            for (int i = 1; i <= n; ++i) {
                if (ok[i] && point[u].check(point[i])) {
                    unit(i, u);
                }
            }
        } else {
            cin >> u >> v;
            if (find(u) == find(v)) {
                cout << "SUCCESS\n";
            } else {
                cout << "FAIL\n";
            }
        }
    }
}