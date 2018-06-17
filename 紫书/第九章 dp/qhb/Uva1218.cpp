#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
const int INF = 1<<28;
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
int dp[3][MAX];// 0 - this node is a server  2 - both this node and its father are not server
// 1 - its father is a server, it is not a server
void dfs(int now, int fa) {
	int v;
	dp[0][now] = 1;
	dp[1][now] = 0;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		dfs(v, now);
		dp[0][now] += min(dp[0][v], dp[1][v]);
		dp[1][now] += dp[2][v];
		if (dp[0][now] >= INF)	dp[0][now] = INF;
		if (dp[1][now] >= INF)	dp[1][now] = INF;
	}

	dp[2][now] = INF;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		dp[2][now] = min(dp[2][now], dp[1][now] - dp[2][v] + dp[0][v]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n) {
		int u, v;
		memset(head, 0, sizeof(head));
		for (int i = 1; i < n; ++i) {
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
		cin >> n;
		dfs(1, -1);
		cout << min(dp[0][1], dp[2][1]) << '\n';
	}
}
