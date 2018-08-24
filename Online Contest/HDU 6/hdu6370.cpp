#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
    int v;
    bool isWolf;
    Node(int a = 0, bool b = 0): v(a), isWolf(b) {}
};
vector<Node>G[MAX];
void add(int u, int v, bool type) {
    G[u].push_back(Node(v, type));
}
vector<Node>GG[MAX];
void add_(int u, int v, bool type) {
    GG[u].push_back(Node(v, type));
}
int scc_cnt, belong[MAX], s[MAX], top, number[MAX], low[MAX], cnt;
vector<int>scc[MAX];
void dfs(int u) {
    number[u] = low[u] = ++cnt;
    s[++top] = u;
    int v = G[u][0].v;
    if (!number[v]) {
        dfs(v);
        low[u] = min(low[u], low[v]);
    } else if (!belong[v]) {
        low[u] = min(low[u], number[v]);
    }
    

    if (low[u] == number[u]) {
        ++scc_cnt;
        scc[scc_cnt].clear();
        int x;
        while (true) {
            x = s[top--];
            scc[scc_cnt].push_back(x);
            belong[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

bool isWolf[MAX], vis[MAX];
void init(int n) {
    memset(belong, 0, sizeof(belong));
    memset(number, 0, sizeof(number));
    memset(isWolf, 0, sizeof(isWolf));
    memset(low, 0, sizeof(low));
    for (int i = 1; i <= n; ++i)    G[i].clear(), GG[i].clear();
    cnt = scc_cnt = top = 0;
}

int ans;
void dfs_(int u) {
    int v;
    int len = GG[u].size();
    for (int i = 0; i < len; ++i) {
        v = GG[u][i].v;
        if (!GG[u][i].isWolf) {
            ++ans;
            dfs_(v);
        }
    }
}
void trajan(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!number[i]) dfs(i);
    }

    int len, sum, idx, u;
    for (int i = 1; i <= scc_cnt; ++i) {
        len = scc[i].size();
        if (len != 1) {
            sum = 0;
            for (int j = 0; j < len; ++j) {
                u = scc[i][j];
                if (G[u][0].isWolf) {
                    ++sum;
                    idx = G[u][0].v;
                }
            }
            if (sum == 1) {
                isWolf[idx] = 1;
                // dfs_(idx);
                ++ans;
                // for (int j = 0; j < len; ++j) {
                //     cout << scc[i][j] << ' ';
                // }
                // cout << endl;
                dfs_(idx);
            }
        }
    }

    // cout << ans << endl;
}


int main() {
    // freopen("input", "r", stdin);
    // freopen("output.a", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, t; char s[10];
        scanf("%d", &n);
        if (n == 1) {
            printf("0 0\n");
            continue;
        }
        init(n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%s", &t, s);
            add(i, t, s[0] == 'w');
            add_(t, i, s[0] == 'w');
        }
        ans = 0;
        trajan(n);

        printf("0 %d\n", ans);
    }
}