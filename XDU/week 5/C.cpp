#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long mat[105][105], dp[105][105];
int nex[105][105], row, col;
void in() {
	cin >> row >> col;
	for (int i = 1; i <= row; ++i)
		for (int j = 1; j <= col; ++j) 
			cin >> mat[i][j];
}
void deal() {
	memset(nex, 0, sizeof(nex));
	for (int i = 1; i <= col; ++i)	dp[row][i] = mat[row][i];

	for (int i = row - 1; i >= 1; --i) {
		for (int j = 1; j <= col; ++j) {
			if (j != col) {
				dp[i][j] = dp[i + 1][j + 1] + mat[i][j];
				nex[i][j] = j + 1;
			}

			if (dp[i][j] > dp[i + 1][j] + mat[i][j]) {
				dp[i][j] = dp[i + 1][j] + mat[i][j];
				nex[i][j] = j;
			}

			if (j != 1 && dp[i][j] > dp[i + 1][j - 1] + mat[i][j]) {
				dp[i][j] = dp[i + 1][j - 1] + mat[i][j];
				nex[i][j] = j - 1;
			}
		}
	}
}
void print() {
	long long ans = 1LL<<50;
	int ansIdx;
	for (int i = col; i >= 1; --i)	if (ans > dp[1][i]) {
		ans = dp[1][i];
		ansIdx = i;
	}

	cout << ans << endl;
	cout << nex[1][3] << endl;
	int nowRow = 2, cnt = ansIdx;
	cout << cnt;
	while (nowRow != row + 1) {
		cnt = nex[nowRow - 1][cnt];
		cout << " " << cnt;
		++nowRow;
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		in();
		deal();
		cout << "Case " << i << endl;
		print();

	}
}
