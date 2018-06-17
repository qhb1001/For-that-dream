#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 3e3 + 5;
int dp[5][MAX], s[MAX], c[MAX], n;
void in() {
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> s[i];
	for (int i = 1; i <= n; ++i)	cin >> c[i];
}
const int INF = 0x3f3f3f3f;
int deal() {
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		dp[1][i] = c[i];
		for (int j = 1; j < i; ++j) if (s[i] > s[j]) {
			// 数量为2 是绝对可以转移的
			dp[2][i] = min(dp[2][i], dp[1][j] + c[i]);

			// 数量为3 从j >= 2转移而来
			if (j >= 2 && dp[2][j] != INF)	dp[3][i] = min(dp[3][i], dp[2][j] + c[i]);
		}
	}
	int ans = INF;
	for (int i = 3; i <= n; ++i)
			ans = min(ans, dp[3][i]);
	if (ans == INF)	return -1;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	in();
	cout << deal() << endl;
}
