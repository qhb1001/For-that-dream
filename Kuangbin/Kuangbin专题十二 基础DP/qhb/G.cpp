#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int T[MAX][12], dp[2][12];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b;
	while(cin >> n && n) {
		memset(T, 0, sizeof(T));
		memset(dp, -1, sizeof(dp));
		int Time = 0;
		while(n--) {
			cin >> a >> b;
			++T[b][a];
			if(b > Time)	Time = b;
		}
		bool flag = 1;
		dp[flag][5] = 0;
		for(int i = 1; i <= Time; ++i) {
			flag = !flag;
			for(int j = 0; j < 11; ++j) {
				if(j == 0)	dp[flag][j] = max(dp[!flag][j], dp[!flag][j + 1]);
				else if(j == 10)	dp[flag][j] = max(dp[!flag][j], dp[!flag][j - 1]);
				else {
					dp[flag][j] = max(dp[!flag][j], max(dp[!flag][j + 1], dp[!flag][j - 1]));
				}
			}

			for(int j = 0; j < 11; ++j)
				if(dp[flag][j] != -1)
					dp[flag][j] += T[i][j];
		}

		int ans = 0;
		for(int i = 0; i < 11; ++i)
			if(dp[flag][i] > ans)	ans = dp[flag][i];
		cout << ans << '\n';
	}
}
