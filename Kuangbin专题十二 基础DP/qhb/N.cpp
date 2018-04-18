#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int a[1005], dp[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		dp[i] = 1;
	}

	int ans = 0;
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j < i; ++j)
			if(a[i] > a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				ans = max(ans, dp[i]);
			}	
	}

	cout << ans << '\n';
}
