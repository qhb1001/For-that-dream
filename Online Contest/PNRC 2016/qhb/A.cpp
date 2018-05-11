#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int len = s.size();
	int dp[100];
	for (int i = 0; i < len; ++i) {
		dp[i] = 1;
		for(int j = 0; j < i; ++j)
			if (s[i] > s[j])	dp[i] = max(dp[i], dp[j] + 1);
	}

	int ans = 0;
	for (int i = 0; i < len; ++i)	ans = max(dp[i], ans);
	cout << 26 - ans << endl;
}
