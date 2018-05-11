#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[55], dp[2][55];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];

	for (int i = 1; i <= n; ++i) {
		//以该位结尾，下降
		dp[0][i] = 1;
		for (int j = 1; j < i; ++j)
			if (a[j] > a[i])	dp[0][i] = max(dp[0][i], dp[1][j] + 1);
		dp[1][i] = 1;
		for (int j = 1; j < i; ++j)
			if (a[j] < a[i])	dp[1][i] = max(dp[1][i], dp[0][j] + 1);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)	ans = max(ans, max(dp[0][i], dp[1][i]));
	cout << ans << endl;
}
