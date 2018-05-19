#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 2e4 + 5;
int dp[MAX];//使用滚动数组，从右往左进行更新，从t - 1开始更新
int t, song[55], n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, kast = 1;
	cin >> T;
	while (T--) {
		cin >> n >> t;
		for (int i = 1; i <=n; ++i) {
			cin >> song[i];
		}
		//song[++n] = 678;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		//解的产生分为两个阶段，第一个阶段是在t - 1的范围之内寻找到能够唱的最多的歌曲
		//之后再加一首劲歌金曲即可
		for (int i = 1; i <= n; ++i) {
			for (int j = t - 1 - song[i]; j >= 0; --j) {//只关心转移到的这些状态
				if (dp[j] != -1)	dp[j + song[i]] = max(dp[j + song[i]], dp[j] + 1);
			}
		}

		int Max = 0;
		for (int i = 1; i <= t - 1; ++i)	
			if (dp[i] > Max)	Max = dp[i];

		int ansT;
		for (int i = t - 1; i >= 0; --i)	
			if (dp[i] == Max) {
				ansT = i + 678;
				Max++;
				break;
			}


		cout << "Case " << kast++ << ": " << Max << " " << ansT << '\n';
	}
}
