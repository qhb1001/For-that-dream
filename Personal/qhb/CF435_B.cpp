#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
vector<int>G[MAX];
int colorNumber[2], color[MAX];
void paint(int now, int fa, int type) {
	colorNumber[type]++;
	color[now] = type;
	int v, len = G[now].size();
	for (int i = 0; i < len; ++i) {
		v = G[now][i];
		if (v == fa)	continue;
		paint(v, now, !type);
	}
}
ll ans = 0;
void dfs(int now, int fa) {
	int len = G[now].size(), v;
	if (color[now] == 1) {
		ans += colorNumber[0] - len;
	}
	for (int i = 0; i < len; ++i) {
		v = G[now][i];
		if (v == fa)	continue;
		dfs(v, now);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int u, v, n;
	cin >> n;
	--n;
	while (n--) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	paint(1, -1, 1);
	dfs(1, -1);
	cout << ans << endl;
}
