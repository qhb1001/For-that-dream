#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e3 + 5;
int head[MAX], cnt = 0;
struct Node {
	int idx, nex;
}e[MAX * MAX];
inline void add(int u, int v) {
	++cnt;
	e[cnt].idx = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
	++cnt;
	e[cnt].idx = u;
	e[cnt].nex = head[v];
	head[v] = cnt;
}

int low[MAX], number[MAX], scc[MAX];
void dfs(int u, int fa) {
	low[u] = number[u] = ++cnt;
	int v, child = 0;
	for (int i = head[u]; i; i = e[i].nex) {
		v = e[i].idx;
		if (!number[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			child++;
			if (low[v] >= number[u])	scc[u]++;
		} else if (number[v] < number[u] && v != fa) {
			low[u] = min(low[u], number[v]);
		}
	}

	if (child == 1 && fa == -1)	scc[u] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int u, v, T = 1;
	while (cin >> u && u) {
		cin >> v;
		memset(number, 0, sizeof(number));
		memset(low, 0, sizeof(low));
		memset(scc, 0, sizeof(scc));
		memset(head, 0, sizeof(head));
		cnt = 0;
		add(u, v);
		int root = MAX;
		while (cin >> u && u) {
			cin >> v;
			add(u, v);
			root = u;
		}

		cnt = 0;
		dfs(root, -1);
		//if (scc[root] == 1)	scc[root] = 0;
		//else if (scc[root] > 1)	scc[root]--;

		if (scc[root] != 0)	scc[root]--;
		cout << "Network #" << T++ << '\n';
		bool flag = 0;
		for (int i = 0; i < MAX; ++i) if (scc[i]) {
			cout << "  SPF node " << i << " leaves " << scc[i] + 1 << " subnets\n";		
			flag = 1;
		}

		if (!flag)	cout << "  No SPF nodes\n";
		cout << '\n';
	}
}
