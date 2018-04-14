#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char dp[105][205][105];
string ans[205];
int main() {
	ans[1] = "1";
	for(int n = 2; n <= 200; ++n) {
		memset(dp, 0, sizeof(dp));
		dp[1][1][0] = '1';
		for(int i = 1; i < 100; ++i)
			for(int j = 1; j < n; ++j)
				if(dp[i][j][i - 1] != '\0') {
					memcpy(dp[i + 1][(j * 10) % n], dp[i][j], sizeof(dp[i][j]));
					dp[i + 1][(j * 10) % n][i] = '0';
					memcpy(dp[i + 1][(j * 10 + 1) % n], dp[i][j], sizeof(dp[i][j]));
					dp[i + 1][(j * 10 + 1) % n][i] = '1';
				}

		for(int i = 100; i >= 0; --i)
			if(dp[i][0][0] != '\0')	{
				ans[n] = dp[i][0];
				break;
			}
	}
	int n;
	while(scanf("%d", &n) && n) {
		printf("%s\n", ans[n].c_str());
	}
}
