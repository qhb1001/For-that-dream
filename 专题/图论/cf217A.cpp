#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 105;
int cnt[MAX], fa[MAX], n;
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v)    return ;
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}
struct Point {
    int x, y;
}p[MAX];
int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) fa[i] = i, cnt[i] = 1;

    for (int i = 1; i <= n; ++i)    scanf("%d%d", &p[i].x, &p[i].y);

    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) if (p[i].x == p[j].x || p[i].y == p[j].y) unit(i, j);

    int ans = 0;
    for (int i = 1; i <= n; ++i) if (fa[i] == i)    ++ans;

    printf("%d\n", ans - 1);
    
}   