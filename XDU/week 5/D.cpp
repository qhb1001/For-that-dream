#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int pie[11][MAX], maxT, n;
void in() {
	int idx, T;
	maxT = 0;
	memset(pie, 0, sizeof(pie));
	while (n--) {
		cin >> idx >> T;
		++pie[idx][T];
		maxT = max(maxT, T);
	}
}
int deal() {
	int dp[2][11];
	bool flag = 0;
	memset(dp, -1, sizeof(dp));

	dp[flag][5] = 0;
	for (int i = 1; i <= maxT; ++i) {
		//首先移动
		for (int j = 0; j < 11; ++j) {
			if (j == 0) {
				dp[!flag][j] = max(dp[flag][0], dp[flag][1]);
			} else if (j == 10)	{
				dp[!flag][j] = max(dp[flag][10], dp[flag][9]);
			} else {
				dp[!flag][j] = max(dp[flag][j], max(dp[flag][j - 1], dp[flag][j + 1]));
			}
		}

		flag = !flag;
		for (int j = 0; j < 11; ++j)
			dp[flag][j] += pie[j][i];
	}

	int ans = 0;
	for (int j = 0; j < 11; ++j)	ans = max(ans, dp[flag][j]);
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n && n) {
		in();
		cout << deal() << endl;
	}
}
