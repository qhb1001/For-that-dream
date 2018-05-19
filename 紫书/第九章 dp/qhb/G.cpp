#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int cnt, ok[1005][1005];
string a;
int dp[1005], len;
void getOk() {
	for (int i = 0; i < len; ++i) {
		ok[i][i] = cnt;
		//首先以该点作为中心，枚举奇数长度
		for (int k = 1; ; ++k) {
			if (i - k < 0)	break;
			if (i + k == len)	break;
			if (a[i - k] == a[i + k])	ok[i - k][i + k] = cnt;
			else	break;
		}

		if (i == len - 1)	break;
		//以点右边的轴作为中心，枚举偶数长度
		for (int k = 1; ; ++k) {
			if (i - k + 1 < 0)	break;
			if (i + k == len)	break;
			if (a[i - k + 1] == a[i + k])	ok[i - k + 1][i + k] = cnt;
			else	break;
		}
	}
}

void deal() {
	dp[0] = 1;
	for (int i = 1; i < len; ++i) {
		dp[i] = 1<<30;
		if (ok[0][i] == cnt)	{
			dp[i] = 1;
			continue;
		}
		for (int j = i - 1; j >= 0; --j) {
			if (ok[j + 1][i] == cnt)	dp[i] = min(dp[i], dp[j] + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		++cnt;
		cin >> a;
		len = a.size();
		getOk();
		deal();
		cout << dp[len - 1] << '\n';
	}
}
