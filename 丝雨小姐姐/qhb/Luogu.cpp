#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 205;
int dp[MAX][MAX], t[MAX];
#define INF 0x3f3f3f3f
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q, u, v, w, n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)	cin >> t[i];
	memset(dp, INF, sizeof(dp));
	while (m--) {
		cin >> u >> v >> w;
		dp[u][v] = dp[v][u] = w;
	}
	cin >> q;
	int cnt = 0;
	while (q--) {
		cin >> u >> v >> w;
		while (cnt != n && t[cnt] <= w) {
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					dp[i][j] = min(dp[i][j], dp[i][cnt] + dp[cnt][j]);
			++cnt;
		}

		if (t[u] > w || t[v] > w || dp[u][v] == INF)	cout << -1 << '\n';
		else	cout << dp[u][v] << '\n';
	
	}
}
