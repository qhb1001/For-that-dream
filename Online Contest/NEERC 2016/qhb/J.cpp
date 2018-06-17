#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 2050;
string in[MAX];
struct Node {
	int to, nex;
}e[MAX<<1];
vector<int>G[MAX];

int head[MAX], match[MAX], vis[MAX], cnt;
void add(int u, int v) {
	// ++cnt;
	// e[cnt].to = v;
	// e[cnt].nex = head[u];
	// head[u] = cnt;
	G[u].push_back(v);
}
bool dfs(int now) {
	int v;
	vis[now] = 1;
	for (int i = 0; i < G[now].size(); ++i) {
		v = G[now][i];
		if (match[v] == -1 || !vis[match[v]] && dfs(match[v])) {
			match[now] = v;
			match[v] = now;
			return true;
		}

	}
	return false;
}
int n, m;
int first(string now) {
	return now[0] + now[1] + now[2];
}
int second(string now) {
	return now[3] + now[4] + now[5];
}
void input() {
	for (int i = 1; i <= m + n; ++i)	cin >> in[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = n + 1; j <= n + m; ++j) {
			if (first(in[i]) == second(in[j]))	{
				add(i, j);
				continue;
			}
			if (first(in[j]) == second(in[i]))	{
				add(i, j);
			}
		}
	}

}

int hungarian() {
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 1; i <= n; ++i) {
		if (match[i] == -1) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i))	++ans;
		}
	}
	return ans;
}
int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	while (cin >> n >> m) {
		cnt = 0;
		memset(head, 0, sizeof(head));
		input();

		cout << hungarian() << '\n';
		for (int i = 1; i <= n; ++i) {
			if (match[i] != -1) {
				int u = i, v = match[i];
				if (first(in[i]) != second(in[match[i]]))	swap(u, v);
				if (u <= v)	cout << "AT ";
				else	cout << "TA ";
				cout << in[u] << " " << in[v] << endl;
			}
		}
	}
	return 0;
}
