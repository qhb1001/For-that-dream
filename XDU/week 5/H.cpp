#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int row, col, dp[11][11][11][11], G[11][11];
void in() {
	int x, y, val;
	memset(G, 0, sizeof(G));
	dp[1][0][1][0] = dp[1][0][0][1] = dp[0][1][1][0] = dp[0][1][0][1] = 0;
	while (cin >> x >> y >> val && x) {
		G[x][y] = val;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> row && row) {
		col = row;
		in();
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j)
				for (int k = 1; k <= row; ++k)
					for (int l = 1; l <= row; ++l) {
						dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]), max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])) + G[i][j] + G[k][l];
						if (i == k && j == l)	dp[i][j][k][l] -= G[i][j];
					}
		cout << dp[row][row][row][row] << endl;
	}
}
