#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e5 + 5;
string dp[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string in;
	cin >> in;
	int len = in.size();

	dp[0] = in[0];
	for (int i = 1; i < len; ++i) {
		if (in[i] > dp[i - 1][0])	dp[i] = in[i];
		else	dp[i] = dp[i - 1] + in[i];
	}

	string ans = "a";
	for (int i = 0; i < len; ++i)
		if (ans < dp[i])	ans = dp[i];
	
	cout << ans << '\n';
}
