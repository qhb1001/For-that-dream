#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e4 + 5;
int head[MAX], cnt;
struct Node {
	int to, nex;
}e[50005];
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}

int low[MAX], number[MAX], s[MAX], top, scc, belong[MAX];
void dfs(int u) {
	number[u] = low[u] = ++cnt;
	s[++top] = u;
	int v;
	for (int i = head[u]; i; i = e[i].nex) {
		v = e[i].to;
		if (!number[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (!belong[v]) {
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

int n, m, in[MAX], out[MAX];
void deal() {
	int v;
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j; j = e[j].nex) {
			v = e[j].to;
			if (belong[v] != belong[i]) ++in[belong[v]], ++out[belong[i]];
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		memset(number, 0, sizeof(number));
		memset(low, 0, sizeof(low));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(belong, 0, sizeof(belong));
		cnt = 0;
		memset(head, 0, sizeof(head));

		cin >> n >> m;
		int u, v;
		while (m--) {
			cin >> u >> v;
			add(u, v);
		}

		scc = 0;
		for (int i = 1; i <= n; ++i) {
			if (!number[i])	dfs(i);
		}

		deal();

		if (scc == 1) {
			cout << 0 << '\n';
			continue;
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 1;  i<= scc; ++i) {
			cnt1 += (in[i] == 0);
			cnt2 += (out[i] == 0);
		}

		cout << max(cnt1, cnt2) << '\n';
	}
}
