#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, r;
struct Node {
	int l, r, val;
	void in() {
		cin >> l >> r >> val;
	}
	bool operator < (const Node& b) const {
		return r < b.r;
	}
}tempNode;
vector<Node>q;
int dp[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;
	for(int i = 1; i <= m; ++i) {
		tempNode.in();
		q.push_back(tempNode);
	}

	sort(q.begin(), q.end());
	dp[0] = q[0].val;
	for(int i = 1; i < m; ++i) {
		dp[i] = q[i].val;
		for(int j = 0; j < i; ++j)
			if(q[i].l - q[j].r >= r && dp[i] < dp[j] + q[i].val)
				dp[i] = dp[j] + q[i].val;

	}

	int ans = 0;
	for(int i = 0; i < m; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}
