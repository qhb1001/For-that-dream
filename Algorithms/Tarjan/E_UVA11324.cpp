#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1005;
int head[MAX], cnt;
struct Node {
	int to, nex;
}e[50005];
int low[MAX], number[MAX], scc, belong[MAX], s[MAX], top, dp[MAX];
int m, n, Head[MAX], size_[MAX];//用来保存联通分量的大小
Node E[MAX];
void init() {
	memset(low, 0, sizeof(low));
	memset(number, 0, sizeof(number));
	memset(belong, 0, sizeof(belong));
	memset(head, 0, sizeof(head));
	memset(dp, 0, sizeof(dp));
	memset(Head, 0, sizeof(Head));
	memset(size_, 0, sizeof(size_));
	scc = cnt = 0;
}
void dfs(int u) {
	number[u] = low[u] = ++cnt;
	int v;
	s[++top] = u;
	for (int i = head[u]; i; i = e[i].nex) {
		v = e[i].to;
		if (!number[v]) {
			dfs(v);
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
			size_[scc]++;
			if (x == u)	break;
		}
	}
}

void add1(int u, int v) {//建读入的图
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}

void add2(int u, int v) {
	++cnt;
	E[cnt].to = v;
	E[cnt].nex = Head[u];
	Head[u] = cnt;
}

void buildGraph() {
	cnt = 0;
	int v;
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j; j = e[j].nex) {
			v = e[j].to;
			if (belong[v] != belong[i])	add2(belong[i], belong[v]);
		}
	}
}

int deal(int now) {
	if (dp[now])	return dp[now];
	int Max = 0;
	for (int i = Head[now]; i; i = E[i].nex) {
		Max = max(Max, deal(E[i].to));
	}
	return dp[now] = Max + size_[now];
}

void print(int now) {
	cout << now << endl;
	for (int i = head[now]; i; i = E[i].nex) {
		dfs(E[i].to);
	}
	cout << now << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, u, v;
	cin >> T;
	while (T--) {
		init();
		cin >> n >> m;
		while (m--) {
			cin >> u >> v;
			add1(u, v);
		}

		//may bot be a connected graph
		for (int i = 1; i <= n; ++i) {
			if (!number[i])	dfs(i);
		}

		buildGraph();
		int ans = 0;
		for (int i = 1; i <= scc; ++i)
			ans = max(ans, deal(i));

		cout << ans << '\n';
	}
}
