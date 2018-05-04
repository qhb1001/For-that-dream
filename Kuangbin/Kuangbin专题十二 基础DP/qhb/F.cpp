#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e4 + 5;
int dp[MAX], val[MAX], cost[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int E, F;
		cin >> E >> F;
		F -= E;
		memset(dp, -1, sizeof(dp));
		dp[0] = 0;
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> val[i] >> cost[i];

		for(int i = 1; i <= n; ++i)
			for(int j = cost[i]; j <= F; ++j)
				if(dp[j - cost[i]] != -1 && dp[j] != -1)
					dp[j] = min(dp[j], dp[j - cost[i]] + val[i]);
				else if(dp[j - cost[i]] != -1 && dp[j] == -1)
					dp[j] = dp[j - cost[i]] + val[i];
		if(dp[F] == -1)	cout << "This is impossible.\n";
		else cout << "The minimum amount of money in the piggy-bank is " << dp[F] << ".\n";
	}
}
