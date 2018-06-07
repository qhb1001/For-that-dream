#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2005;
int head[MAX], cnt, n;
struct Node {
	int to, nex;
}e[MAX<<1];
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}
bool vis[MAX];
int dfs(int now, int fa, int depth) {
	int ans = depth, v;
	vis[now] = 1;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		ans = max(ans, dfs(v, now, depth + 1));
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int temp;
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		if (temp == -1)	continue;
		add(temp, i);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) if (!vis[i]) {
		ans = max(ans, dfs(i, -1, 1));
	}

	cout << ans << endl;
}
