#include <iostream>
#include <cstdio>
using namespace std;
int row, col, G[15][105];
int dp[15][105], nex[15][105];
const int INF = 0x3f3f3f3f;
int dfs(int r, int c) {
	if (dp[r][c] != INF)	return dp[r][c];

	if (c == col) return dp[r][c] = G[r][c];

	int now, Next;
	for (int i = -1; i <= 1; ++i) {
		now = r + i;
		if (now == 0)	now = row;
		if (now == row + 1)	now = 1;
		
		if (dfs(now, c + 1) + G[r][c] < dp[r][c])	{
			dp[r][c] = dfs(now, c + 1) + G[r][c];
			Next = now;
		} else if (dfs(now, c + 1) + G[r][c] == dp[r][c] && now < Next) {
			Next = now;
		}
	}

	nex[r][c] = Next;
	return dp[r][c];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> row >> col) {
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j) 
				cin >> G[i][j];
	
		memset(dp, 0x3f3f3f3f, sizeof(dp));
		int Min = 1<<30, idx;
		for (int i = 1; i <= row; ++i)	{
			dfs(i, 1);
			if (dp[i][1] < Min)	{
				Min = dp[i][1];
				idx = i;
			} 
		}

		cout << idx;
		for (int i = 2; i <= col; ++i) {
			idx = nex[idx][i - 1];
			cout << " " << idx;
		}
		cout << '\n' << Min << '\n';
	}
}
