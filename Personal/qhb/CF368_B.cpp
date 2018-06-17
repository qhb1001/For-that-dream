#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
	int to, cost;
	Node(int a = 0, int b = 0): to(a), cost(b) {}
}now;
vector<Node>G[MAX];
vector<int>ans;
bool haveFlour[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, u, v, cost;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> cost;
		G[u].push_back(Node(v, cost));
	}
	while (k--) {
		cin >> u;
		haveFlour[u] = 1;
	}

	int len;
	for (int i = 1; i <= n; ++i) {
		len = G[i].size();
		for (int j = 0; j < len; ++j) {
			now = G[i][j];
			if (haveFlour[i] + haveFlour[now.to] == 1) ans.push_back(now.cost);
		}
	}

	len = ans.size();
	if (len == 0)	cout << -1 << endl;
	else {
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}
	return 0;
}
