#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define fir first
#define sec second
const int N = 1005, M = 1e4+5, INF = 1e9+5;
inline int read(){
    char c=getchar(); int x=0,f=1;
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
    return x*f;
}

int n, m, k, u, v, w, s, t;
namespace I {
    struct edge{int v, ne, w;} e[M];
    int cnt, h[N];
    inline void ins(int u, int v, int w) { 
        e[++cnt] = (edge){v, h[u], w}; h[u] = cnt;
    }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    int vis[N];
    void dij(int s, int t, int *d) {
        for(int i=1; i<=n; i++) d[i] = INF, vis[i] = 0;
        d[s] = 0; q.push(make_pair(0, s));
        while(!q.empty()) {
            int u = q.top().sec; q.pop(); 
            if(vis[u]) continue; vis[u] = 1;
            for(int i=h[u];i;i=e[i].ne) {
                int v = e[i].v;
                if(d[v] > d[u] + e[i].w) 
                    d[v] = d[u] + e[i].w, q.push(make_pair(d[v], v));
            }
        }
    }
}

int d_t[N];

struct edge{int v, ne, w;} e[M];
int cnt, h[N];
inline void ins(int u, int v, int w) {
    e[++cnt] = (edge){v, h[u], w}; h[u] = cnt;
}
priority_queue<pii, vector<pii>, greater<pii> > q;
int vis[N], ans[10005], tt;
void a_star(int s, int t) {
    I::dij(t, s, d_t);
    if (d_t[s] == INF || d_t[s] > t)  return ;
    while (!q.empty()) q.pop();


    for(int i=1; i<=n; i++) vis[i] = 0;
    q.push(make_pair(d_t[s], s));
    while(!q.empty()) {
        int u = q.top().sec, d = q.top().fir; q.pop(); 
        vis[u]++;
        if(u == t) { 
            ans[vis[t]] = d;
            if(vis[t] == k) return;
        }
        if (d > t)  return ;
        if(vis[u] <= k) for(int i=h[u];i;i=e[i].ne) {
            
            int v = e[i].v;
            q.push(make_pair(d - d_t[u] + d_t[v] + e[i].w, v));
        }
    }
}

int d[N];
vector<pair<int, int> >G_[N];
void dijkstra() {
    queue<int>q;
    q.push(t);
    int len, u, v;
    for (int i = 1; i <= n; ++i) d[i] = 1<<30, vis[i] = false;
    vis[t] = 1;
    d[t] = 0;
    while (!q.empty()) {
        u = q.front(); q.pop(); vis[u] = false;
        
        len = G_[u].size();
        for (int i = 0; i < len; ++i) {
            v = G_[u][i].first;
            if (d[v] > d[u] + G_[u][i].second) {
                d[v] = d[u] + G_[u][i].second;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
struct Node {
    int h, g, u;
    Node(int a = 0, int b = 0, int c = 0) {
        h = a; g = b; u = c;
    }
    bool operator < (const Node b) const {
        return h + g > b.h + b.g;
    }
}now;

void input() {
    s = read(); t = read(); k = read(); tt = read();
    for(int i=1; i<=m; i++) u=read(), v=read(), w=read(), I::ins(v, u, w), ins(u, v, w); 
    memset(ans, -1, sizeof(ans));
}
int main() {
    while (scanf("%d%d", &n, &m) != EOF) { 
    	cnt = 0; I::cnt = 0;
        input();
        if (s >= 1000000) printf("-1");
        
        
        a_star(s, t);
        if (ans[k] != -1 && ans[k] <= tt) printf("yareyaredawa\n");
        else printf("Whitesnake!\n");
    }
}

