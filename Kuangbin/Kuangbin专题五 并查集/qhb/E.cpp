#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 5e4 + 5;
int fa[MAX * 3], cnt[MAX * 3], n, m;
void init() {
	for(int i = 0; i <= n; ++i) {
		cnt[i] = cnt[i + MAX] = cnt[i + MAX * 2] = 1;
		fa[i] = i;fa[i + MAX] = i + MAX;fa[i + MAX * 2] = i + MAX * 2;
	}
}
int find(int x) {
	return fa[x] == x? x : fa[x] = find(fa[x]);
}
void unit(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v)	return ;
	if(cnt[v] > cnt[u])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ans = 0, type, a, b;
	init();
	for(int i = 1; i <= m; ++i) {
		cin >> type >> a >> b;
		if(a > n || b > n) {
			++ans;
			continue;
		}
		if(type == 1) {
			if(find(a) == find(b + 2 * MAX) || find(b) == find(a + 2 * MAX)) {
				++ans;
				continue;
			}
			unit(a + MAX, b);
			unit(b + MAX, a);
			unit(a + 2 * MAX, b + 2 * MAX);
		} else {
			if(a == b || find(a) == find(b + MAX) || find(b) == find(a + MAX)) {
				++ans;
				continue;
			}
			unit(b, a + 2 * MAX);
			unit(b + MAX, a + 2 * MAX);
		}
	}
	cout << ans << '\n';
}
