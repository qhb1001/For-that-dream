#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 3005;
int G[MAX][MAX];
int n, m;
vector<int>e[MAX];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        G[u][v] += 1;
        e[u].push_back(v);
    }

    long long ans = 0, cnt;
    int temp;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cnt = 0; if (i == j)    continue;
            for (int k : e[i]) {
                if (k != i && k != j && G[i][k] && G[k][j])
                    ++cnt;
            }
            ans += cnt * (cnt - 1) / 2;
        }
    }

    printf("%lld\n", ans);

}