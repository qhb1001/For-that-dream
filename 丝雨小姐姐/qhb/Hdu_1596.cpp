#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1005;
double dp[MAX][MAX];
const double INF = 1LL<<50;
int n;
void in() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%lf", &dp[i][j]);
			if (dp[i][j] == 0)	dp[i][j] = INF;
			else	dp[i][j] = -log10(dp[i][j]);
		}
}
void deal() {
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
}
int main() {
	while (~scanf("%d", &n)) {
		in();
		deal();
		int q, u, v;
		double ans;
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &u, &v);
			ans = dp[u][v];
			if (ans == INF)	printf("What a pity!\n");
			else	printf("%.3lf\n", pow(10, -dp[u][v]));
		}
	}
}
