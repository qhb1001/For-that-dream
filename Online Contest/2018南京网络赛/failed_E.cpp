#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 22;
int head[MAX], cnt, n, m, in[MAX], a[MAX], b[MAX], t;
long long ans;
struct Edge {
    int to, nex;
}e[MAX*MAX];
void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
void solve() {
    priority_queue<pair<int, int> >q;
    for (int i = 1 ; i<= n; ++i)    if (!in[i]) q.push(make_pair(a[i], i));
    pair<int, int> now;
    int u, v;
    while (!q.empty()) {
        now = q.top(); q.pop();
        u = now.second;
        ans += 1LL * t * a[u] + b[u];
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            in[v]--;

        }
    }
}
int main() {

}