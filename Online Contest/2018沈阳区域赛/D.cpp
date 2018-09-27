#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
inline int read(){
    char c=getchar(); int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int MAX = 1e3 + 5;
vector<pair<int, int> >G[MAX], G_[MAX];
int n, m, s, e, k, t, d[MAX], vis[MAX];
void input() {
    s = read(); e = read(); k = read(); t = read();

    for (int i = 1; i <= n; ++i) {G[i].clear(); G_[i].clear();}
    for (int i = 1, u, v, c; i <= m; ++i) {
        u = read(); v = read(); c = read();
        G[u].push_back(make_pair(v, c));
        G_[v].push_back(make_pair(u, c));
    }
}
void dijkstra() {    
    priority_queue<pair<int, int> >q;

    for (int i = 1; i <= n; ++i) d[i] = 1<<30, vis[i] = false;
    d[e] = 0;
    q.push(make_pair(0, e));
    pair<int, int> now;
    int u, v, len;
    while (!q.empty()) {
        now = q.top(); q.pop();
        u = now.second;

        if (vis[u] || d[u] < now.first)   continue;
        vis[u] = true;
        len = G_[u].size();
        for (int i = 0; i < len; ++i) {
            v = G_[u][i].first;
            if (!vis[v] && d[v] > d[u] + G_[u][i].second) {
                d[v] = d[u] + G_[u][i].second;
                q.push(make_pair(d[v], v));
            }
        }
    }
}
struct Node {
    int g, u;
    ll h;
    Node(ll a = 0, int b = 0, int c = 0) {
        h = a; g = b; u = c;
    }
    bool operator < (const Node b) const {
        return h + g > b.h + b.g;
    }
}now;

priority_queue<Node>q;
int solve() {
    while (!q.empty()) q.pop();

    q.push(Node(0, d[s], s));
    memset(vis, 0, sizeof(vis));

    int len, num = 0, u, v;
    while (!q.empty()) {
        now = q.top(); q.pop(); u = now.u;
        vis[u]++;
        if (now.u == e) ++num;
        if (num == k)   return now.h;
        if (now.h > t)  continue;

        len = G[u].size();
        if (vis[u] <= k ) for (int i = 0; i < len; ++i) {
            v = G[u][i].first;
            q.push(Node(G[u][i].second + now.h, d[v], v));
        }
    }

    return -1;
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        input();
        dijkstra();
        if ((d[s] == (1<<30)) || d[s] > t) {printf("Whitesnake!\n"); continue;}


        int now = solve();
        if (now == -1 || now > t) printf("Whitesnake!\n");
        else printf("yareyaredawa\n");
    }
}