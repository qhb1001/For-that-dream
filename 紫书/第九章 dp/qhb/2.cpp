#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 45;
bool vis[MAX];
int dp[MAX][MAX][MAX][MAX], top[4], candy[MAX][4], h;
void init() {
	memset(dp, -1, sizeof(dp));
	top[0] = top[1] = top[2] = top[3] = 0;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < 4; ++j)
			scanf("%d", &candy[i][j]);
}

int dfs(int now) {
	int &temp = dp[top[0]][top[1]][top[2]][top[3]];
	if (dp[top[0]][top[1]][top[2]][top[3]] != -1)	return temp;
	if (now == 5)	return temp = 0;
	int toTake;
	temp = 0;
	for (int i = 0; i <4; ++i) {
		if (top[i] != h) {
			toTake = candy[top[i]][i];
			if (vis[toTake]) {
				vis[toTake] = 0;
				++top[i];
				temp = max(temp, dfs(now - 1) + 1);
				--top[i];
				vis[toTake] = 1;
			} else {
				vis[toTake] = 1;
				++top[i];
				temp = max(temp, dfs(now + 1));
				--top[i];
				vis[toTake] = 0;
			}
		}
	}
	return temp;
}
int main() {
	while (scanf("%d", &h) && h) {
		init();
		printf("%d\n", max(0, dfs(0)));
	}
}
