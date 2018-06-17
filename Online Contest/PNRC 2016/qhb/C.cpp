#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 55;
int dp[MAX][MAX][MAX], row, col;
struct Node {
	int x, y, step;
	Node(int a = 0, int b = 0, int c = 0): x(a), y(b), step(c) {}
}now, nex;
int beginX, beginY, endX, endY;
char G[MAX][MAX], command[MAX];
void in() {
	scanf("%d%d", &row, &col);
	for (int i = 1; i <= row; ++i) {
		scanf("%s", G[i] + 1);
		for (int j = 1; j <= col; ++j) {
			if (G[i][j] == 'E') {
				endX = i;
				endY = j;
			} else if (G[i][j] == 'R') {
				beginX = i;
				beginY = j;
			}
		}
	}
	scanf("%s", command + 1);
}
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
map<char, int>dir;
int bfs() {
	dir['R'] = 0; dir['L'] = 1; dir['D'] = 2; dir['U'] = 3;
	queue<Node>q;
	q.push(Node(beginX, beginY, 1));//第三个参数代表下一步应该走的指令操作
	int len = strlen(command + 1);
	memset(dp, 0x3f3f3f3f, sizeof(dp));
	dp[beginX][beginY][1] = 0;
	while (q.empty() == 0) {
		now = q.front(); q.pop();
		//随机插入一个方向
		nex.step = now.step;
		for (int i = 0; i < 4; ++i) {
			nex.x = now.x + X[i];
			nex.y = now.y + Y[i];
			if (nex.x < 1 || nex.y < 1 || nex.x > row || nex.y > col || G[nex.x][nex.y] == '#')
				continue;
			if (dp[nex.x][nex.y][nex.step] > dp[now.x][now.y][now.step] + 1) {
				dp[nex.x][nex.y][nex.step] = dp[now.x][now.y][now.step] + 1;
				q.push(nex);
			}
		}

		if (now.step == len + 1)	continue;
		//执行当前指令
		nex.x = now.x + X[dir[command[now.step]]];
		nex.y = now.y + Y[dir[command[now.step]]];
		// if (command[now.step] == 'D') {
		// 	cout << "The current step is " << now.step << " and the the cost of now is " << dp[now.x][now.y][now.step] << endl;
		// 	cout << now.x << " " << now.y << "    " << nex.x << " " << nex.y << endl;
		// }
		nex.step = now.step + 1;
		if (nex.x < 1 || nex.y < 1 || nex.x > row || nex.y > col || G[nex.x][nex.y] == '#') {
			nex = now;
			nex.step = now.step + 1;
		}
		if (dp[nex.x][nex.y][nex.step] > dp[now.x][now.y][now.step]) {
			dp[nex.x][nex.y][nex.step] = dp[now.x][now.y][now.step];
			q.push(nex);
		}

		//删除当前指令
		nex = now;
		nex.step = now.step + 1;
		if (dp[nex.x][nex.y][nex.step] > dp[now.x][now.y][now.step] + 1) {
			dp[nex.x][nex.y][nex.step] = dp[now.x][now.y][now.step] + 1;
			q.push(nex);
		}
	}

	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= len + 1; ++i)
		ans = min(ans, dp[endX][endY][i]);
	return ans;
}
int main() {
	in();
	printf("%d\n", bfs());
}
