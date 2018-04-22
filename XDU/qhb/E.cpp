#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 5;
char a[MAX];
long long dp[MAX][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(scanf("%s", a) != EOF) {
		int len = strlen(a);
		memset(dp, 0, sizeof(dp));
		dp[0][a[0] - '0'] = 1;
		for(int i = 1; i < len; ++i) {
			for(int j = 0; j < 3; ++j)
				dp[i][(j * 10 + a[i] - '0') % 3] += dp[i - 1][j];
			dp[i][a[i] - '0']++;
		}
		long long sum = 0;
		for(int i = 0; i < len; ++i)
			sum += dp[i][0];
		cout << sum << endl;
	}
}
