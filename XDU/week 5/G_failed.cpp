#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int dp[2][MAX], a[MAX], b[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		
		for (int i = 1; i <= n; ++i)	cin >> a[i];
		for (int i = 1; i <= m; ++i)	cin >> b[i];

		bool flag = 1;
		dp[flag][0] = dp[!flag][1] = dp[!flag][0] = dp[flag][1] = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (a[i] == b[j])	dp[!flag][j] = dp[flag][j - 1] + 1;
				else	dp[!flag][j] = max(dp[flag][j], dp[!flag][j - 1]);
				flag = !flag;
			}

		cout << dp[flag][m] << endl;
	}
}
