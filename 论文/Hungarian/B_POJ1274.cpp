#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 405;
int head[MAX], cnt, n, m;
int match[MAX], vis[MAX], T;
struct Node {
	int to, nex;
}e[MAX * MAX];
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}
bool dfs(int now) {
	vis[now] = 1;
	int v;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (match[v] == -1 || !vis[match[v]] && dfs(match[v])) {
			match[now] = v;
			match[v] = now;
			return true;
		}
	}
	return false;
}
void in() {
	int len, to;
	for (int i = 1; i <= n; ++i) {
		cin >> len;
		while (len--) {
			cin >> to;
			add(i, 200 + to);
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
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m) {
		memset(head, 0, sizeof(head));
		in();
		cout << hungarian() << endl;
	}
}
