#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
using namespace std;
const int MAX= 1e5 + 5;
int n, m, k, s, type[MAX], head[MAX], cnt;
struct Node {
    int to, nex;
}e[MAX<<1];
void add(int u, int v) {
    ++cnt;
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
void in() {
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; ++i)    cin >> type[i];
    int u, v;
    while (m--) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
}
struct node {
    int to, dis;
    node(int a = 0, int b = 0) {
        to = a;
        dis = b;
    }
};
int bfs(int x) {
    int ans = 0, ok = 1, v;
    queue<node>q;
    node now;
    bool vis[MAX] = {0};
    bool okType[200] = {0};
    vis[x] = okType[type[x]] = 1;
    q.push(node(x, 0));
    while (true) {
        now = q.front(); q.pop();
        for (int i = head[now.to]; i; i = e[i].nex) {
            v = e[i].to;
            if (!vis[v] && !okType[type[v]]) {
                vis[v] = okType[type[v]] = 1;
                ans += now.dis + 1;
                q.push(node(v, now.dis + 1));
                ++ok;
                if (ok == s)    return ans;
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    in();

    for (int i = 1; i <= n; ++i)    cout << bfs(i) << " ";
	cout << endl;
}
