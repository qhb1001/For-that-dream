#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int row, col, mp[105][105], dp[105][105];
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
int dfs(int nowx, int nowy) {
	if (dp[nowx][nowy])	return dp[nowx][nowy];

	dp[nowx][nowy] = 1;
	for (int i = 0; i < 4; ++i) {
		int x = nowx + X[i];
		int y = nowy + Y[i];
		if (x < 1 || y < 1 || x > row || y > col || mp[x][y] >= mp[nowx][nowy])	continue;
		dp[nowx][nowy] = max(dp[nowx][nowy], dfs(x, y) + 1);
	}
	return dp[nowx][nowy];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string name;
		cin >> name >> row >> col;

		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j)	
				cin >> mp[i][j];
		int ans = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j) 
				ans = max(dfs(i, j), ans);

		cout << name << ": " << ans << '\n';
	}
}
