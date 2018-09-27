#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int n, m, head[MAX], cnt, pre[MAX];
long long d[MAX];
bool vis[MAX];
struct Edge {
    int to, nex, cost;
}e[MAX<<1];
void add(int u, int v, int cost) {
    e[++cnt] = (Edge){v, head[u], cost};
    head[u] = cnt;
}
void dijkstra() {    
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > >q;
    for (int i = 1; i <= n; ++i) d[i] = 1LL<<50;
    d[1] = 0;
    q.push(make_pair(0, 1));
    pair<long long, int> now;
    int u, v;
    while (!q.empty()) {
        now = q.top(); q.pop();
        u = now.second;

        if (vis[u] || d[u] < now.first)   continue;
        vis[u] = true;
        
        if (u == n) return ;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (!vis[v] && d[v] > d[u] + e[i].cost) {

                d[v] = d[u] + e[i].cost;
                q.push(make_pair(d[v], v));
                pre[v] = u;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n >> m;
    int u, v, c;
    while (m--) {
        cin >> u >> v >> c;
        add(u, v, c);
        add(v, u, c);
    }
    dijkstra();
    if (pre[n] == 0)    cout << -1 << endl;
    else {
        int now = n;
        stack<int> ans;
        while (true) {
            ans.push(now); now = pre[now];
            if (now == 1)   {ans.push(1); break;}
        }

        while (!ans.empty())    {cout << ans.top() << ' '; ans.pop(); }
    }
}