#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int row, col, G[15][1005];
const int INF = 1<<30;
void in() {
	for (int i = 1 ; i<= row; ++i)
		for (int j = 1; j <= col; ++j)	cin >> G[i][j];
}
struct Node {
	int nex, path;
}dp[15][1005];
int min(int a, int b) {
	if (a == -1)	return b;
	if (b == -1)	return a;
	if (a < b)	return a;
	return b;
}
void init() {
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 1000; ++j)
			dp[i][j].path = dp[i][j].nex = INF;

	for (int i = 1; i <= row; ++i)
		dp[i][1].path = G[i][1];
}

int Next[15][105];
void deal(int r, int c) {
	int now;
	for (int i = -1; i <= 1; ++i) {
		now = r + i;
		if (now <= 0)	now = row;
		else if (now > row)	now = 1;
		if (dp[now][c + 1].path > dp[r][c].path + G[now][c + 1]) {
			dp[now][c + 1].path = dp[r][c].path + G[now][c + 1];
		}
	}
}

void getNext() {
	int now;
	for (int i = 1; i < col; ++i) {
		for (int j = 1; j <= row; ++j) {//枚举将要求解的Next点
			int Min = 1<<30, nex;
			for (int k = -1; k <= 1; ++k) {
				now = j + k;
				if (now <= 0)	now = row;
				if (now > row)	now = 1;
				if (dp[now][i + 1].path < Min) {
					Min = dp[now][i + 1].path;
					nex = now;
				} else if (dp[now][i + 1].path == Min && now < nex) {
					now = nex;
				}
			}
			Next[j][i] = nex;
		}
	}
}
int s[1005], top;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> row >> col) {
		in();
		init();

		for (int i = 2; i <= col; ++i)
			for (int j = 1; j <= row; ++j)
				deal(j, i);

		int idx, Min = 1<<30;
		int pp;

		cout << dp[1][2].pre <<" here" << endl;
		for (int i = 1; i <= row; ++i) {
			if (dp[i][col].path < Min) {
				Min = dp[i][col].path;
				idx = i;
				pp = dp[i][col].pre;
			} else if (dp[i][col].path == Min && pp > dp[i][col].pre) {
				pp = dp[i][col].pre;
				idx = i;
			}

		}
		top = 0;
		int cnt = dp[idx][col].pre, c = col - 1;
		s[++top] = idx;
		while (cnt != INF) {
			s[++top] = cnt;
			cnt = dp[cnt][c--].pre;
		}

		cout << s[top--];
		while (top)	cout << " " << s[top--];
		cout << '\n' << Min << '\n';
	}
}
