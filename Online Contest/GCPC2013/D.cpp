#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int MAX = 105;
typedef long long ll;
pair<int, int> p[MAX];
int n, d[MAX];
bool vis[MAX];
bool bfs() {
    queue<int> q;
    q.push(1);
    memset(d, 0, sizeof(d));
    d[1] = 1000;
    memset(vis, 0, sizeof(vis));
    vis[1] = true;
    int u, v, val, x;
    while (!q.empty()) {
        u = q.front(); q.pop();
        vis[u] = false;

        if (u == n) return true;
        for (int i = 1; i <= n; ++i) {
            val = abs(p[i].first - p[u].first) + abs(p[i].second - p[u].second);
            if (val <= d[u]) {
                x = d[u] - val;
                val = floor((1000 - x) / 50.0) * 50 + x;
                if (val > d[i]) {
                    d[i] = val; 
                    if (!vis[i])    {vis[i] = true; q.push(i);}    
                }

            }
        }
    }

    return false;

}
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        n += 2;
        for (int i = 1; i <= n; ++i)   scanf("%d%d", &p[i].first, &p[i].second);
        if (bfs())  printf("happy\n");
        else printf("sad\n");
    }
}