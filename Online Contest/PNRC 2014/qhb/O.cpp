#include <iostream>
#include <cstdio>
using namespace std;
struct Node {
	double weight, value;
}a[205];
bool check(Node a, Node b) {
	if (a.weight > b.weight && a.value < b.value)	return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)	cin >> a[i].weight >> a[i].value;
		int dp[205] = {0};
		for (int i = 1; i <= n; ++i) {
			dp[i] = 1;
			for (int j = 1; j < i; ++j)
				if (check(a[i], a[j]))	dp[i] = max(dp[i], dp[j] + 1);
		}

		int ans = 0;
		for (int i = 1; i <= n; ++i)	ans = max(ans, dp[i]);
		cout << ans << endl;
	}
}
