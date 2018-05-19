#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int MAX = 105;
int head[MAX], cnt;
struct Node {
	int to, nex;
}e[MAX * MAX];
int scc, belong[MAX], low[MAX], number[MAX], s[MAX], top = 0;
void dfs(int u) {
	low[u] = number[u] = ++cnt;
	int v;
	s[++top] = u;
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

int out[MAX], in[MAX];
void deal() {
	int v;
	for (int i = 1; i < MAX; ++i) {
		for (int j = head[i]; j; j = e[j].nex) {
			v = e[j].to;
			if (belong[i] != belong[v]) {
				out[belong[i]]++;
				in[belong[v]]++;
			}
		}
	}
}

void add(int u, int v) {
	++cnt;
	e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int u, v;
	for (u = 1; u <= n; ++u) {
		while (cin >> v && v) {
			add(u, v);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!number[i])	dfs(i);
	}

	deal();
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1;  i <= scc; ++i) {
		if (!in[i])	++cnt1;
		if (!out[i])	++cnt2;
	}
	
	if (scc == 1)	{
		cout << 1 << endl << 0 << endl;
		return 0;
	}
	cout << cnt1 << '\n' << max(cnt1, cnt2) << '\n';
}
