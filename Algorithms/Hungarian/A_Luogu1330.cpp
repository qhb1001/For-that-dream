#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e4 + 5;
int n, m, head[MAX], cnt, vis[MAX];
struct Node {
	int to, nex;
}e[200005];
int num[2];//represent the number of each color
int color[MAX];//represent the color of node i
bool dfs(int now, bool type) {
	if (color[now] != -1) {
		if (color[now] == type)	return true;
		return false;//已经染色，并且出现冲突
	}
	++num[type];
	color[now] = type;
	int v;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (!dfs(v, !type))	return false;
	}
	return true;
}
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}
void in() {
	cin >> n >> m;
	int u, v;
	while (m--) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
}
int deal() {
	in();
	int ans = 0;
	memset(color, -1, sizeof(color));
	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1) {
			num[0] = num[1] = 0;
			if (dfs(i, 0) == false)	return -1;
			ans += min(num[0], num[1]);
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = deal();
	if (ans == -1)	cout << "Impossible\n";
	else	cout << ans << endl;

}
