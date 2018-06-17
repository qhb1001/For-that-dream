#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
char G[55][55], command[55];
int row, col;
void in() {
	scanf("%d%d", &row, &col);
	for (int i = 1; i <= row; ++i)	scanf("%s", G[i] + 1);
	scanf("%s", command + 1);
}
int dp[55][55][55];
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
int deal() {
	memset(dp, INF, sizeof(dp));
	int beginX, beginY, endX, endY;
	for (int i = 1; i <= row; ++i)
		for (int j = 1; j <= col; ++j)
			if (G[i][j] == 'R') {
				beginX = i; beginY = j;
			} else if (G[i][j] == 'E') {
				endX = i; endY = j;
			}


	dp[0][beginX][beginY] = 0;
	int len = strlen(command + 1), x, y, now;
	for (int stage = 1; stage <= len; ++stage) {
		//尝试添加操作
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j) if (dp[stage - 1][i][j] != INF) {
				if (i == endX && j == endY)	continue;
				for (int k = 0; k < 4; ++k) {
					x = i + X[k];
					y = j + Y[k];
					now = dp[stage - 1][i][j] + 1;
					while (true) {
						if (x < 1 || y < 1 || x > row || y > col || G[x][y] == '#')	break;
						dp[stage][x][y] = min(dp[stage][x][y], now);
						++now;
						x += X[k]; y += Y[k];
					}
				}
				
			}

		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j)
				dp[stage - 1][i][j] = min(dp[stage - 1][i][j], dp[stage][i][j]);

		//删除操作以及执行操作，从上面得到的stage以及stage - 1中转移而来
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j) if (dp[stage - 1][i][j] != INF) {
				if (i == endX && j == endY)	continue;
				//花费1时间取消掉该指令
				dp[stage][i][j] = min(dp[stage][i][j], dp[stage - 1][i][j] + 1);

				//使用该指令进行转移
				if (command[stage] == 'U')	x = i - 1, y = j;
				else if (command[stage] == 'D')	x = i + 1, y = j;
				else if (command[stage] == 'L')	x = i, y = j - 1;
				else	x = i, y = j + 1;

				if (x < 1 || y < 1 || x > row || y > col || G[x][y] == '#') {
					dp[stage][i][j] = min(dp[stage][i][j], dp[stage - 1][i][j]);
				} else {
					dp[stage][x][y] = min(dp[stage][x][y], dp[stage - 1][i][j]);
				}
			}
	}
	int ans = INF;
	for (int i = 1; i <= len; ++i)
		ans = min(dp[i][endX][endY], ans);
	return ans;
}
int main() {
	in();

	//deal();
	int stage, i, j;
	//while (cin >> stage >> i >> j) {
	//	cout << dp[stage][i][j] << endl;
	//}
	printf("%d\n", deal());
}
