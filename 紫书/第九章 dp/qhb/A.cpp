#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool Left[55][5005], Right[55][5005];
int t[55], n, T;
void preTreatment() {
	int m, now;
	memset(Left, 0, sizeof(Left));
	memset(Right, 0, sizeof(Right));
	cin >> m;
	while (m--) {
		cin >> now;
		for (int i = 1; i < n; ++i) {
			now += t[i - 1];
			Right[i][now] = 1;//表示在第i个车站  now时刻有一辆开往右方的列车
		}
	}

	cin >> m;
	while (m--) {
		cin >> now;
		for (int i = n; i > 1; --i) {
			now += t[i];
			Left[i][now] = 1;
		}
	}
}

int dp[55][202];
int min(int a, int b) {
	if (a == -1)	return b;
	if (b == -1)	return a;
	if (a < b)	return a;
	return b;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int cnt = 1;
	while (cin >> n && n) {
		memset(dp, -1, sizeof(dp));
		memset(t, 0, sizeof(t));
		cin >> T;
		for (int i = 1; i < n; ++i)	cin >> t[i];
		preTreatment();

		dp[1][0] = 0;
		for (int i = 0; i <= T; ++i) {
			//在这个时刻，枚举每一个车站的状态，使用刷表法
			for (int j = 1; j <= n; ++j) {
				if (dp[j][i] != -1) {
					//首先在这个位置待一秒
					dp[j][i + 1] = min(dp[j][i + 1], dp[j][i] + 1);

					if (Right[j][i]) {//如果有向右的车
						dp[j + 1][i + t[j]] = min(dp[j + 1][i + t[j]], dp[j][i]);
					}

					if (Left[j][i]) {//如果有向左的车
						dp[j - 1][i + t[j - 1]] = min(dp[j - 1][i + t[j - 1]], dp[j][i]);
					}
				}
			}
		}

		cout << "Case Number " << cnt++ << ": ";
		if (dp[n][T] == -1)	cout << "impossible\n";
		else	cout << dp[n][T] << '\n';
	}

}
