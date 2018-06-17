#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const double EPS = 1e-4;
double a[20][20], dp[20][20][20];//represent in the range of [l, r] the probrability of team idx to win
bool vis[20][20][20];
double dfs(int l, int r, int toWin) {
	if (vis[l][r][toWin])	return dp[l][r][toWin];
	vis[l][r][toWin] = 1;
	int mid = (l + r) >> 1;
	dp[l][r][toWin] = 0;
	if (l + 1 == r) {
		if (toWin == l)	return dp[l][r][l] = a[l][r];
		else	return dp[l][r][r] = a[r][l];
	}

	if (toWin <= mid) {
		for (int i = mid + 1; i <= r; ++i)
			dp[l][r][toWin] += dfs(l, mid, toWin) * dfs(mid + 1, r, i) * a[toWin][i];
		return dp[l][r][toWin];
	} else {
		for (int i = l; i <= mid; ++i)
			dp[l][r][toWin] += dfs(l, mid, i) * dfs(mid + 1, r, toWin) * a[toWin][i];
		return dp[l][r][toWin];
	}
}
int main() {
	for (int i = 1; i <= 16; ++i)
		for (int j = 1; j <= 16; ++j)	
			scanf("%lf", &a[i][j]);

	printf("%.6lf", dfs(1, 16, 1));
	for (int i = 2; i <= 16; ++i)	printf(" %.6lf", dfs(1, 16, i));

	printf("\n");

}
