#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int MAX = 110;
int head[MAX], cnt, degree[MAX], n, m;
bool vis[MAX];
struct Edge {
    int to, nex;
}e[MAX*MAX];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}
vector<int>ans;
void topoSort() {
    queue<int>q;

    ans.clear();
    int u, v;
    for (int i = 1; i <= n; ++i) if (!degree[i]) {
        q.push(i);
    }

    while (!q.empty()) {
        u = q.front(); q.pop();
        ans.push_back(u);
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            degree[v]--;
            if (!degree[v]) q.push(v);
        }
    }
    

    printf("%d", ans[0]);
    int len = ans.size();
    for (int i = 1; i < len; ++i) printf(" %d", ans[i]);
    printf("\n");
}
void input() {
    cnt = 0;
    memset(head, 0, sizeof(head));
    int u, v;
    memset(degree, 0, sizeof(degree));

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
        degree[v]++;
    }

}
int main() {

    while (scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0)   break;
        input();
        topoSort();
    }
}
