#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 5;
int a[MAX], b[MAX];
int dp[2][MAX];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			dp[0][a[i]] = dp[0][a[i] - 1] + 1;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &b[i]);
			dp[1][b[i]] = dp[1][b[i] - 1] + 1;
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i)
			ans = max(ans, min(dp[0][a[i]], dp[1][a[i]]));
		for (int i = 1; i <= m; ++i)
			ans = max(ans, min(dp[0][b[i]], dp[1][b[i]]));

		printf("%d\n", ans);
		for (int i = 1; i <= n; ++i)	dp[0][a[i]] = 0;
		for (int i = 1; i <= m; ++i)	dp[1][b[i]] = 0;
	}
}
