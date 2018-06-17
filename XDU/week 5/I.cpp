#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 3e5 + 5;
int dp[MAX][26], head[MAX], cnt, letter[MAX];
bool in[MAX], flag;
struct Node {
	int to, nex;
}e[MAX];
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}

int n, m, belong[MAX], low[MAX], number[MAX], s[MAX], top, scc;
void dfs_(int u) {
	number[u] = low[u] = ++cnt;
	int v;
	s[++top] = u;
	for (int i = head[u]; i; i = e[i].nex) {
		v = e[i].to;
		if (!number[v]) {
			dfs_(v);
			low[u] = min(low[u], low[v]);
		} else if (!belong[v])	{
			low[u] = min(low[u], number[v]);
		}
	}

	int x;
	if (low[u] == number[u]) {
		++scc;
		while (true) {
			x = s[top--];
			belong[x] = scc;
			if (x == u)	break;
		}
	}
}
bool haveCircle() {
	for (int i = 1; i <= n; ++i)
		if (!number[i])	dfs_(i);
	if (scc != n)	return true;
	return false;
}
bool vis[MAX];
int dfs(int now, int toFind) {
	int v, ans = 0;
	vis[now] = 1;
	if (dp[now][toFind] != -1)	return dp[now][toFind];
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		ans = max(ans, dfs(v, toFind));
	}
	if (letter[now] == toFind)	++ans;
	return dp[now][toFind] = ans;
}

void input() {
	cin >> n >> m;
	string a;
	cin >> a;
	for (int i = 0; i < n; ++i)
		letter[i + 1] = a[i] - 'a';
	int u, v;
	while (m--) {
		cin >> u >> v;
		add(u, v);
		if (u == v)	flag = 1;
		in[v] = 1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	if (flag || haveCircle())	{
		cout << -1 << endl;
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	int ans = 0;
	// for (int i = 1; i <= n; ++i) if (!in[i]) {
	// 	for (int j = 0; j < 26; ++j)
	// 		ans = max(ans, dfs(i, j));
	// }
	for (int i = 0; i < 26; ++i) {
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j <= n; ++j)
			ans = max(ans, dfs(j, i));
	}
	cout << ans << endl;
}
