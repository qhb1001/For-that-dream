#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 22;
int head[MAX], cnt, n, m, in[MAX], a[MAX], b[MAX], nowIn[MAX], nexIn[MAX];
long long ans;
struct Edge {
    int to, nex;
}e[MAX*MAX];
void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
long long dp[1<<20];
struct Node {
    int t, status;
    long long sum;
    bool operator < (const Node b) const {
        return sum < b.sum;
    }
}now, nex;
void solve() {
    priority_queue<Node>q;
    now.t = 1; now.status = 0;
    q.push(now);
    bool  flag;
    int u, v, Max, idx;
    while (!q.empty()) {
        now = q.top(); q.pop();
        ans = max(ans, now.sum);

        if (now.sum < dp[now.status])   continue;

        memcpy(nowIn, in, sizeof(in));
        for (int i = 1; i <= n; ++i) if ((now.status & (1<<(i - 1))) != 0) {
            for (int j = head[i]; j; j = e[j].nex) --nowIn[e[j].to];
        }

        Max = -(1<<30); flag = false;
        for (int i = 1; i <= n; ++i) if (!nowIn[i] && ((now.status & (1<<(i - 1))) == 0)) {
            if (Max < a[i]) {Max = a[i]; flag = false; idx = i;}
            else if (Max == a[i]) {flag = true;}
        }

        if (Max == -(1<<30))    continue;
        
        if (!flag) {
            nex.status = (now.status | (1<<(idx - 1)));
            nex.sum = now.sum + 1LL * now.t * a[idx] + b[idx];
            if (dp[nex.status] >= nex.sum)  continue;
            nex.t = now.t + 1;
            q.push(nex);
            continue;
        }

        for (int i = 1; i <= n; ++i) if (!nowIn[i] && ((now.status & (1<<(i - 1))) == 0) && a[i] == Max) {
            nex.status = (now.status | (1<<(i - 1)));
            nex.sum = now.sum + 1LL * now.t * a[i] + b[i];
            if (dp[nex.status] >= nex.sum)  continue;
            nex.t = now.t + 1;
            q.push(nex);
        }
    }
}
int main() {
    scanf("%d", &n);
    int len, u, v;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &a[i], &b[i], &len);
        v = i;
        for (int j = 1; j <= len; ++j) {scanf("%d", &u); add(u, v); in[v]++;}
    }

    solve();
    printf("%lld\n", ans);
}
