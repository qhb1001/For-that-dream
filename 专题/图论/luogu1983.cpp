#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1005;
bool isExist[MAX][MAX], vis[MAX];
vector<int>G[MAX];
int n, m, ans, degree[MAX];
vector<int>temp;
void topoSort() {
    queue<pair<int, int> >q;
    for (int i = 1; i <= n; ++i) if (!degree[i])    q.push(make_pair(i, 1));

    int len, u, v;
    pair<int, int> now;
    while (!q.empty()) {
        now = q.front(); q.pop();
        u = now.first;
        len = G[u].size();
        for (int i = 0; i < len; ++i) {
            v = G[u][i];
            degree[v]--;
            if (!degree[v]) {
                q.push(make_pair(v, now.second + 1));
                ans = max(ans, now.second + 1);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    int len, t;
    for (int i = 1; i <= m; ++i) {
        temp.clear();
        scanf("%d", &len);
        memset(vis, 0, sizeof(vis));
        for (int j = 1; j <= len; ++j) {
            scanf("%d", &t);
            temp.push_back(t);
            vis[t] = 1;
        }
        for (int j = temp[0]; j < temp[len - 1]; ++j) if (!vis[j]) {
            for (int k = 0; k < len; ++k) if (!isExist[j][temp[k]]) {
                isExist[j][temp[k]] = 1;
                G[j].push_back(temp[k]);
                degree[temp[k]]++;
            }
        }
    }
    topoSort();
    printf("%d\n", ans);
}