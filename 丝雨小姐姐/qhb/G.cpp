#include <stack>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e4 + 5;
int n, fa[MAX], cnt[MAX], m;
stack<int>s;
void init() {
	for (int i = 0; i <= n; ++i) fa[i] = i, cnt[i] = 1;
}
int find(int u) {
	return fa[u] == u? u : fa[u] = find(fa[u]);
}
bool unit(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)	return false;
	if (cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
	return true;
}
struct Node {
	int u, v;
	void in() {
		cin >> u >> v;
	}
}e[100005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m) {
		init();
		for (int i = 1; i <= m; ++i)	e[i].in();

		int now = n;
		while (s.empty() == 0)	s.pop();
		for (int i = m; i >= 1; --i) {
			s.push(now);
			now -= unit(e[i].u, e[i].v);
		}

		while (s.empty() == 0) {
			cout << s.top() << '\n';
			s.pop();
		}
	}
}
