#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 22;
int head[MAX], cnt, n, m, in[MAX], a[MAX], b[MAX];
long long ans;
struct Edge {
    int to, nex;
}e[MAX*MAX];
void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
struct Node {
    int in[MAX], t;
    long long sum;
}now;
void solve() {
    queue<Node>q;
    memcpy(now.in, in, sizeof(in));
    now.t = 1;
    now.sum = 0;
    q.push(now);
    while (!q.empty()) {
        now = q.front(); q.pop();
        ans = max(ans, now.sum);

        for (int i = 1; i <= n; ++i) if (!now.in[i]) {

        }
    }
}