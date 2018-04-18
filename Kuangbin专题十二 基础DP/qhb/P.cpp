#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
int row, col, k, G[105][105], dp[105][105];
int deal(int x, int y) {
	if(dp[x][y] != -1)	return dp[x][y];
	int nowx, nowy;
	dp[x][y] = G[x][y];
	for(int i = 0; i < 4; ++i)
		for(int j = 1; j <= k; ++j) {
			nowx = x + X[i] * j;
			nowy = y + Y[i] * j;
			if(nowx < 0 || nowy < 0 || nowx >= row || nowy >= col || G[nowx][nowy] <= G[x][y])	continue;
			dp[x][y] = max(dp[x][y], deal(nowx, nowy) + G[x][y]);
		}
	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> row >> k) {
		col = row;
		memset(dp, -1, sizeof(dp));
		if(row == -1)	break;
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j) 
				cin >> G[i][j];

		cout << deal(0, 0) << '\n';
	}
}
