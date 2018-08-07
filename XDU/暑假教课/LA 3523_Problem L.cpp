#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
using namespace std;
const int MAX = 1e3 + 5;
struct Edge {
    int to, nex;
}e[MAX * MAX];
int head[MAX], cnt;
void add(int u, int v) {
    ++cnt;
    e[cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
struct Node {
    int u, v;
    Node(int a = 0, int b = 0): u(a), v(b) {}
};


bool A[MAX][MAX], iscut[MAX];
int n, m, number[MAX], low[MAX], bcc_cnt, bccno[MAX];
stack<Node>s;
vector<int>bcc[MAX];

void dfs(int u, int fa) {
    number[u] = low[u] = ++cnt;
    int v, child = 0;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (!number[v]) {
            s.push(Node(u, v));
            dfs(v, u);
            low[u] = min(low[u],low[v]);
            ++child;
            if (low[v] >= number[u]) {
                iscut[u] = true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;) {
                    Node x = s.top(); s.pop();
                    if (bccno[x.u] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    }

                    if (bccno[x.v] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }

                    if (x.u == u && x.v == v)   break;
                }
            }
        } else if (number[v] < number[u] && v != fa) {
            s.push(Node(u, v));
            low[u] = min(low[u], number[v]);
        }
    }

    if (fa == -1 && child == 1) iscut[u] = 0;
}

void find_bcc(int n) {
    memset(number, 0, sizeof(number));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    cnt = bcc_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!number[i]) dfs(i, -1);
    }
}

int odd[MAX], color[MAX];
bool bipartite(int u, int b) {
    int v;
    for (int i = head[u]; i; i = e[i].nex) {
        v = e[i].to;
        if (bccno[v] != b)  continue;
        if (color[v] == color[u])   return false;
        if (!color[v]) {
            color[v] = 3 - color[u];
            if (!bipartite(v, b))   return false;
        }
    }
    return true;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 1;
    while (cin >> n >> m && n) {
        memset(head, 0, sizeof(head));
        cnt = 0;
        int u, v;
        for (int i = 1; i <= m; ++i) {
            cin >> u >> v;
            A[u][v] = A[v][u] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (!A[i][j]) {
                    add(i, j); add(j, i);
                }
            }
        }

        find_bcc(n);

        memset(odd, 0, sizeof(odd));
        for (int i = 1; i <= bcc_cnt; ++i) {
            memset(color, 0, sizeof(color));
            //针对割点的操作，保证在处理某个双连通分量时割点
            for (int j = 0; j < bcc[i].size(); ++j) {
                bccno[bcc[i][j]] = i;
            }

            int u = bcc[i][0];
            color[u] = 1;
            if (!bipartite(u, i)) {
                for (int j = 0; j < bcc[i].size(); ++j) {
                    odd[bcc[i][j]] = 1;
                }
            }
        }

        int ans = n;
        for (int i = 1; i <= n; ++i) if (odd[i])    --ans;
        cout << ans << '\n';
    }
}