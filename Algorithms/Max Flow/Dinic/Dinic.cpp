#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 2e4 + 5;
const int INF = 1<<30;
int level[MAX], vis[MAX], G[MAX][MAX], n, m, s, t;
bool bfs() {
    queue<int>q;
    q.push(s);
    memset(level, -1, sizeof(level)); //maybe it's better to new an array everytime
    level[s] = 0;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        //if (u == t) return true;//这是一个优化，可以使得这个层次图到达汇点的点更多
        for (v = 1; v <= n; ++v) if (level[v] == -1 && G[u][v]) {
            level[v] = level[u] + 1;
            q.push(v);
        }
    }
    if (level[t] != -1) return true;
    return false;
}
int Dinic() {
    int u, v, ans = 0, len, Min, idx;
    deque<int>q;
    while (bfs()) {
        memset(vis, 0, sizeof(vis));
        q.push_back(s);
        vis[s] = 1;
        while (!q.empty()) {
            u = q.back(); 
            if (u == t) {
                len = q.size();
                Min = 1<<30;
                for (int i = 1; i < len; ++i) {
                    u = q[i - 1]; v = q[i];
                    if (Min > G[u][v]) {Min = G[u][v]; idx = u;}
                }

                for (int i = 1; i < len; ++i) {
                    u = q[i - 1]; v = q[i];
                    G[u][v] -= Min;
                    G[v][u] += Min;
                }
                ans += Min;

                while (!q.empty() && q.back() != idx) vis[q.back()] = 0, q.pop_back();
            } else {
                for (v = 1; v <= n; ++v) if (!vis[v] && G[u][v] && level[v] == level[u] + 1) {
                    vis[v] = 1;
                    q.push_back(v);
                    break;
                }
                if (v > n)  q.pop_back();

            }
        }
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, c;
    while (m--) {
        scanf("%d%d%d", &u, &v, &c);
        G[u][v] += c;
    }

    printf("%d\n", Dinic());

}