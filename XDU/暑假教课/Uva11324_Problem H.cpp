#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1005;
int head[MAX], cnt;
struct Node {
    int to, nex;
}e[50005];
void add(int u, int v) {
    ++cnt;
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}

int scc, s[MAX], top, belong[MAX], number[MAX], low[MAX], size_[MAX];
void dfs(int u) {
    s[++top] = u;
    number[u] = low[u] = ++cnt;
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!number[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!belong[v]) {
            low[u] = min(low[u], number[v]);
        }
    }

    if (low[u] == number[u]) {
        int x;
        ++scc;
        while (true) {
            x = s[top--];
            belong[x] = scc;
            size_[scc]++;
            if (x == u) break;
        }
    }
}

int Head[MAX], Cnt;
Node E[50005];
void Add(int u, int v) {
    ++Cnt;
    E[Cnt].to = v;
    E[Cnt].nex = Head[u];
    Head[u] = Cnt;
}
int n, m;
void buildGraph() {
    Cnt = 0;
    int v;
    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; j; j = e[j].nex) {
            v = e[j].to;
            if (belong[i] != belong[v]) Add(belong[i], belong[v]);
        }
    }
}

int dp[MAX];
int deal(int u) {
    if (dp[u])  return dp[u];
    dp[u] = size_[u];
    int v, Max = 0;
    for (int i = Head[u]; i; i = E[i].nex) {
        v = E[i].to;
        Max = max(Max, deal(v));
    }
    return dp[u] += Max;
}
void init() {
    memset(belong, 0, sizeof(belong));
    memset(size_, 0, sizeof(size_));
    memset(head, 0, sizeof(head));
    memset(Head, 0, sizeof(Head));
    memset(number, 0, sizeof(number));
    memset(dp, 0, sizeof(dp));
    memset(low, 0, sizeof(low));
    top = scc = 0;
}

void Print(int now) {
    for (int i = Head[now]; i; i = E[i].nex) {
        cout << E[i].to << ' ';
    }
    cout << endl;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, u, v;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cnt = 0;
        init();
        while (m--) {
            cin >> u >> v;
            add(u, v);
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!number[i]) dfs(i);
        }
        buildGraph();

        // for (int i = 1; i <= 3; ++i) {
        //     Print(i);
        // }
        int ans = 0;
        for (int i = 1; i <= scc; ++i) {
            if (!dp[i]) {
                ans = max(ans, deal(i));
            }
        }

        cout << ans << '\n';
    }
}