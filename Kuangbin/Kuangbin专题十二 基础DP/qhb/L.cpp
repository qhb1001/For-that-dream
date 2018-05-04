#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int dp[1005][1005];
int main() {
	string a, b;
	while(cin >> a >> b) {
		int len1 = a.size(), len2 = b.size();
		a = " " + a;
		b = " " + b;
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= len1; ++i) {
			for(int j = 1; j <= len2; ++j)
				if(a[i] == b[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else 
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}

		cout << dp[len1][len2] << '\n';
	}
}
