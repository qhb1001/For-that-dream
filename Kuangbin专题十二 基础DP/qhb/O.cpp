#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 2005;
int val[2005], dp[2][2005][2005], n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i)	 cin >> val[i];
	memset(dp, -1, sizeof(dp));
	bool flag = 0;
	dp[0][0][n + 1] = 0;
	for(int i = 1; i <= n; ++i) {
		flag = !flag;
		for(int j = 0; j <= i; ++j) {
			if(j == 0) {
				dp[flag][0][n + 1 - (i - j)] = dp[!flag][0][n + 2 - (i - j)] + val[n + 1 - i] * i;
			} else if(i == j) {
				dp[flag][j][n + 1] = dp[!flag][j - 1][n + 1] + val[j] * i;
			} else {
				dp[flag][j][n + 1 - (i - j)] = max(dp[!flag][j - 1][n + 1 - (i - j)] + val[j] * i, dp[!flag][j][n + 1 - (i - j) + 1] + val[n + 1 - (i - j)] * i);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= n; ++i)
		ans = max(dp[flag][i][i + 1], ans);
	cout << ans << '\n';
}
