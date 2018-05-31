#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[41][41][41][41][5];
int h, candy[41][4];
int len[41][41][41][41], ans[41][41][41][41];
void in() {
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= 4; ++j)	
			cin >> candy[i][j];
}

bool isHaveCandy(int a, int b, int c, int d, int e) {
	for (int i = 0; i < 5; ++i)
		if (dp[a][b][c][d][i] == e)	return true;
	return false;
}
bool dfs(int a, int b, int c, int d) {
	if (len[a][b][c][d] != -1)	{
		if (len[a][b][c][d] <= 4)	return true;
		return false;
	}

	len[a][b][c][d] = 1<<30;
	ans[a][b][c][d] = -(1<<30);
	int addCandy;
	//transfer from a
	if (a != h && dfs(a + 1, b, c, d)) {
		//memcpy(dp[a][b][c][d], dp[a + 1][b][c][d], sizeof(dp[a][b][c][d]));
		addCandy = candy[a + 1][1];
		if (isHaveCandy(a + 1, b, c, d, addCandy) && 
				ans[a + 1][b][c][d] + 1 > ans[a][b][c][d]) {
			ans[a][b][c][d] = ans[a + 1][b][c][d];
			len[a][b][c][d] = len[a + 1][b][c][d] - 1;
			//memcpy(dp[a][b][c][d], dp[a + 1][b][c][d], sizeof(dp[a][b][c][d]));

			for (int i = 0; i < 5; ++i) {
				if (dp[a][b][c][d][i] == addCandy)	continue;
				else	dp[a][b][c][d][i] = dp[a + 1][b][c][d][i];
			}
		} 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> h && h) {
		
	}
}
