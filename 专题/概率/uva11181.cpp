#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n, r;
double ans[25], people[25];
bool vis[25];
void dfs(int k, int cnt) {
    if (cnt == r) {
        double now = 1;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) now *= people[i];
            else    now *= (1.0 - people[i]);
        }
        
        ans[0] += now;
        for (int i = 1; i <= n; ++i)    if (vis[i]) ans[i] += now;
    } else {
        if (k > n)  return ;
        vis[k] = 1;
        dfs(k + 1, cnt + 1);
        vis[k] = 0;
        dfs(k + 1, cnt);
    }
}
void init() {
    for (int i = 0; i <= 20; ++i) {
        vis[i] = ans[i] = 0;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);

    for (int kase = 1;; kase++) {
        scanf("%d%d", &n, &r);
        if (n == 0 && r == 0)   break;
        init();
        for (int i = 1; i <= n; ++i)    scanf("%lf", &people[i]);
        printf("Case %d:\n", kase);
        dfs(1, 0);
        for (int i = 1; i <= n; ++i)    printf("%.6lf\n", ans[i] / ans[0]);
    }
}