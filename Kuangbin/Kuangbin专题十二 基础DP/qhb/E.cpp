#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[1005];
long long dp[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n && n) {
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; ++i)	cin >> a[i];
		a[0] = 0;a[n + 1] = 1<<30;
		for(int i = 0; i <= n; ++i) {
			for(int j = i + 1; j <= n + 1; ++j) {
				if(a[j] > a[i])
					dp[j] = max(dp[j], dp[i] + a[i]);
			}
		}
		cout << dp[n + 1] << '\n';
	}
}
