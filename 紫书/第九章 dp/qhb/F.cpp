#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node {
	int v, Cost, cost, n;
	void in() {
		cin >> v >> Cost >> cost >> n;
	}
	bool operator < (const Node b) const {
		return v < b.v;
	}
}lamp[1005];
int prefixN[1005], dp[1005], n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n && n) {
		for (int i = 1; i <= n; ++i) {
			lamp[i].in();
		}

		sort(lamp + 1, lamp + 1 + n);
		for (int i = 1; i <= n; ++i)	prefixN[i] = prefixN[i - 1] + lamp[i].n;
		for (int i = 1; i <= n; ++i) {
			dp[i] = 1<<30;
			for (int j = 0; j < i; ++j) {
				dp[i] = min(dp[i], dp[j] + (prefixN[i] - prefixN[j]) * lamp[i].cost + lamp[i].Cost);
			}
		}

		cout << dp[n] << '\n';
	}
}
