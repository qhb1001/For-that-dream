#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
double dp[55][55];
double INF = 1LL<<40;
struct P {
	double x, y;
}point[55];
int n, T;
double dis(int i, int j) {
	double dx = point[i].x - point[j].x;
	double dy = point[i].y - point[j].y;
	return sqrt(dx * dx + dy * dy);
}
double getArea(int a, int b, int c) {
	return fabs((point[b].x - point[a].x) * (point[c].y - point[a].y) - (point[c].x - point[a].x) * (point[b].y - point[a].y)) / 2.0;
}
double EPS = 1e-6;
bool isZero(double a) {
	if (a < EPS)	return true;
	return false;
}
bool isEqual(double a, double b) {
	if (a - b <= EPS)	return true;
	return false;
}

bool check(int i, int j, int k) {//判断是否有点包含在这个三角形内部
	double a = getArea(i, j, k), b;
	for (int l = 1; l <= n; ++l) {
		if (l == i || l == j || l == k)	continue;
		b = getArea(i, j, l) + getArea(i, l, k) + getArea(l, j, k);
		if (isEqual(b, a) == 1)	return false;
	}
	return true;
}
double dfs(int l, int r) {
	if (!isEqual(dp[l][r], INF))	return dp[l][r];
	if (l + 1 == r)	return dp[l][r] = 0;
	for (int k = l + 1; k < r; ++k) {
		//cout << dp[l][r] << endl;
		if (!check(l, r, k))	continue;
		dp[l][r] = min(dp[l][r], max(dfs(l, k), max(dfs(k, r), getArea(l, r, k))));
	}
	return dp[l][r];
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}
		memset(dp, 0, sizeof(dp));
		for (int len = 2; 1 + len <= n; ++len) {
			for (int i = 1; i + len <= n; ++i) {//枚举起点
				dp[i][i + len] = 1LL<<40;
				for (int j = i + 1; j < i + len; ++j) {//枚举断点
					if (!check(i, j, i + len))	continue;
					dp[i][i + len] = min(dp[i][i + len], max(dp[i][j], max(dp[j][i + len], getArea(i, j, i + len))));
				}
			}
		}
		printf("%.1lf\n", dp[1][n]);
	}
}
