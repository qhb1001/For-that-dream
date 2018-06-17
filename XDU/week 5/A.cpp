#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 105;
int dp[105][105], a[105][105], h;
void in() {
	for (int i = 1; i <= h; ++i) 
		for (int j = 1; j <= i; ++j)
			cin >> a[i][j];
}
int deal() {
	for (int i = 1; i <= h; ++i)	dp[h][i] = a[h][i];
	for (int i = h - 1; i >= 1; --i) 
		for (int j = 1; j <= i; ++j)
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
	return dp[1][1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> h;
		in();
		cout << deal() << endl;
	}
}
