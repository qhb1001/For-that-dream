#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int fa[MAX], cnt[MAX];
void init() {
	for (int i = 0; i < MAX; ++i)
		fa[i] = i, cnt[i] = 1;
}
int find(int u) {
	return fa[u] == u? u : fa[u] = find(fa[u]);
}
bool unit(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)	return true;
	if (cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int u, v, ans = 0;
	while (cin >> u >> v) {
		init();
		unit(u, v);
		ans = 0;
		while (cin >> u) {
			if (u == -1)	break;
			cin >> v;
			ans += unit(u, v);
		}
		cout << ans << '\n';
	}
}
