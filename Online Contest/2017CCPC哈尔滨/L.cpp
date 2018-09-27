#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int down[MAX], up[MAX], n;
vector<int>G[MAX];
void init() {
    for (int i = 1; i <= n; ++i) G[i].clear();
    memset(down, 0, sizeof(down));
    memset(up, 0, sizeof(up));
}
int num[MAX];
int dfs(int u, int fa) {
    num[u] = 1;
    for (int v : G[u]) if (v != fa) num[u] += dfs(v, u);
    return num[u];
}

int nowDown[MAX], nowUp[MAX];
bool solve(int u, int fa, int x) {
    int Down = 0, Up = 1;
    for (int v : G[u]) if (v != fa) {
        if (!solve(v, u, x))   return false;
        Down += nowDown[v];
        Up += nowUp[v];
    }
    nowDown[u] = max(Down, down[u]);
    nowUp[u] = min(Up, x - up[u]);
    if (nowUp[u] < 0)   return false;
    return nowDown[u] <= nowUp[u];
}

int main() {    
    freopen("input.txt", "r", stdin);

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        init();
        for (int i = 1, u, v; i < n; ++i) {
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1);
        int temp; scanf("%d", &temp);
        for (int i = 1, idx, val; i <= temp; ++i) {
            scanf("%d%d", &idx, &val);
            down[idx] = max(down[idx], val);
        }

        bool flag = true;
        scanf("%d", &temp);
        for (int i = 1, idx, val; i <= temp; ++i) {
            scanf("%d%d", &idx, &val);
            if (n - num[idx] + 1 < up[idx]) flag = false;
            up[idx] = max(up[idx], val);
        }

        if (!flag) {printf("-1\n"); continue;}

        int l = 0, r = n, ans = -1, mid;
        while (l <= r) {
            mid = l + r >> 1;
            if (solve(1, -1, mid) && nowDown[1] <= mid && mid <= nowUp[1]) ans = mid, r = mid - 1;
            else l = mid + 1;
        }

        printf("%d\n", ans);
    }

}