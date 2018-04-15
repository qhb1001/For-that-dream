#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m, n;
const int MAX = 1e6 + 5;
const int INF = -(1<<30);
typedef long long ll;
ll dp[2][MAX][2], now;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> m >> n) {
		for(int i = 0; i <= n; ++i)
			dp[0][i][0] = dp[0][i][1] = dp[1][i][1] = dp[1][i][0] = INF;
		bool flag = 1;
		cin >> now;
		dp[flag][1][0] = INF;
		dp[flag][1][1] = now;

		for(int i = 2; i <= n; ++i) {
			cin >> now;
			flag = !flag;
			dp[flag][1][0] = max(dp[!flag][1][0], dp[!flag][1][1]);
			dp[flag][1][1] = max(dp[!flag][1][1] + now, now);
			for(int k = 2; k <= min(i, m); ++k) {
				dp[flag][k][0] = max(dp[!flag][k][0], dp[!flag][k][1]);
				dp[flag][k][1] = max(dp[!flag][k - 1][1] + now, max(dp[!flag][k - 1][0], dp[!flag][k][1]) + now);
			}
		}

		cout << max(dp[flag][m][1], dp[flag][m][0]) << '\n';
	}
}
