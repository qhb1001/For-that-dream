#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1005;
int fa[MAX], cnt[MAX], n, m, u, v;
void init() {
	for (int i = 1; i <= n; ++i)
		fa[i] = i, cnt[i] = 1;
}
int find(int u) {
	return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)	return ;
	if (cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		init();
		while (m--) {
			cin >> u >> v;
			unit(u, v);
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (i == find(i))	++ans;
		cout << ans << '\n';
	}
}
