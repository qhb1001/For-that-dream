#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1005;
int fa[MAX], cnt[MAX];
int find(int x) {
	return fa[x] == x? x : fa[x] = find(fa[x]);
}
void unit(int u, int v) {
	u = find(u);
	v = find(v);
	if(v == u)	return ;
	if(cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
}
void init() {
	for(int i = 0; i <= 1000; ++i)
		fa[i] = i, cnt[i] = 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, tempa, tempb;
	cin >> T;
	while(T--) {
		init();
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= m; ++i) {
			cin >> tempa >> tempb;
			unit(tempa, tempb);
		}

		int ans = 0;
		for(int i = 1; i <= n; ++i)
			if(fa[i] == i)	++ans;
		cout << ans << '\n';
	}
}
