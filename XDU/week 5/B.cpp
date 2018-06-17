#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1005;
int dp[MAX], N, V;
int cost[MAX], val[MAX];
void in() {
	cin >> N >> V;
	for (int i = 1; i <= N; ++i)	cin >> val[i];
	for (int i = 1; i <= N; ++i)	cin >> cost[i];
}
int deal() {
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; ++i) {
		for (int j = V; j >= cost[i]; --j)
			dp[j] = max(dp[j], dp[j - cost[i]] + val[i]);
	}

	return dp[V];
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		in();
		cout << deal() << endl;
	}
}
