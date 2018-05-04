#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int c, m, dp[105][105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, now;
	cin >> T;
	while(T--) {
		memset(dp, 0, sizeof(dp));
		cin >> c >> m;

		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= c; ++j) {
				cin >> now;
				dp[i][j] = max(dp[i][j], dp[i - 1][c - j] + now);
			}
		cout << dp[m][c] << endl;
	}
}
