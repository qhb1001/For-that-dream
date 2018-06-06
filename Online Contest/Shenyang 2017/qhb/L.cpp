#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 5;
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
int dp[MAX];
int dfs(int now, int fa) {
	int v;
	dp[now] = 1;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		dp[now] += dfs(v, now);
	}
	return dp[now];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, k, u, v;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		memset(head, 0, sizeof(head));
		for (int i = 1; i < n; ++i) {
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		dfs(1, -1);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (dp[i] >= k && n - dp[i] >= k)	++ans;
		cout << ans << '\n';
	}
}
