#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 5;
int n[2], a[2][MAX], fa[2][MAX], cnt[2][MAX];
bool vis[2][MAX];
int find(int type, int x) {
	return fa[type][x] == x? x : fa[type][x] = find(fa[type][x]);
}
void unit(int type, int u, int v) {
	u = find(type, u);
	v = find(type, v);
	if (u == v)	return ;
	if (u < v)	swap(u, v);
	fa[type][v] = u;
	cnt[type][u] += cnt[type][v];
}
void init(int type) {
	for (int i = 1; i <= n[type]; ++i) {
		fa[type][a[type][i]] = a[type][i];
		cnt[type][a[type][i]] = 1;
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i < MAX; ++i) {
		fa[0][i] = fa[1][i] = i;
		cnt[0][i] = cnt[1][i] = 1;
	}
	while (T--) {
		scanf("%d%d", &n[0], &n[1]);
		for (int i = 1; i <= n[0]; ++i)	{
			scanf("%d", &a[0][i]);
			if (vis[0][a[0][i] - 1])	unit(0, a[0][i], a[0][i] - 1);
			vis[0][a[0][i]] = 1;
		}
		for (int i = 1; i <= n[1]; ++i)	scanf("%d", &a[1][i]);

	}
}
