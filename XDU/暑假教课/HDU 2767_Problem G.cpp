#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e4 + 5;
int head[MAX], cnt;
struct Node {
    int idx, nex;
}e[50005];
void add(int u, int v) {// before use this function, remember to set cnt = 0;
    ++cnt;
    e[cnt].idx = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}

int scc, s[MAX], top, belong[MAX], low[MAX], number[MAX];
void dfs(int u) {// before this, remember to set cnt = 0;
    number[u] = low[u] = ++cnt;
    s[++top] = u;
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].idx;
        if (!number[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (!belong[v]) {
            low[u] = min(low[u], number[v]);
        }
    }

    if (number[u] == low[u]) {
        int x;
        ++scc;
        while (true) {
            x = s[top--];
            belong[x] = scc;
            if (x == u) break;
        }
    }
}

int n, m, in[MAX], out[MAX];

void deal() {
    int v;
    for (int i = 1; i <= n; ++i) {
        for (int j = head[i]; j; j = e[j].nex) {
            v = e[j].idx;
            if (belong[i] != belong[v]) out[belong[i]]++, in[belong[v]]++;
        }
    }
}
void init() {
    top = 0; scc = 0;
    memset(head, 0, sizeof(head));
    memset(low, 0, sizeof(low));
    memset(number, 0, sizeof(number));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(belong, 0, sizeof(belong));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, u, v;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        cnt = 0;
        while (m--) {
            cin >> u >> v;
            add(u, v);
        }

        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (!number[i]) dfs(i);
        }

        if (scc == 1) {
            cout << 0 << '\n';
            continue;
        }
        deal();
        int cntIn = 0, cntOut = 0;
        for (int i = 1; i <= scc; ++i) {
            cntIn += (in[i] == 0);
            cntOut += (out[i] == 0);
        }
        cout << max(cntIn, cntOut) << '\n';
    }
}
