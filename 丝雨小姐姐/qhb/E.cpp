#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 2005;
const int INF = 0x3f3f3f3f;
struct Day {
	int buyPrice, sellPrice, buyMax, sellMax;
}day[MAX];
struct Node {
	int val, day;
	Node (int a = 0, int b = 0): val(a), day(b) {}
};
int maxn, t, w, dp[MAX][MAX];
deque<Node>q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> t >> maxn >> w;
		for (int i = 1; i <= t; ++i)
			cin >> day[i].buyPrice >> day[i].sellPrice >> day[i].buyMax >> day[i].sellMax;

		for (int i = 0; i <= t; ++i)
			for (int j = 0; j <= maxn; ++j)
				dp[i][j] = -INF;

		for (int i = 1; i <= w + 1; ++i) {
			for (int j = 0; j <= day[i].buyMax; ++j)
				dp[i][j] = -j * day[i].buyPrice;
		}


		int temp;
		for (int i = 2; i <= t; ++i) {
			for (int j = 0; j <= maxn; ++j)	dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (i <= w + 1)	continue;
			while (q.empty() == 0)	q.pop_back();
			for (int j = 0; j <= maxn; ++j) {
				temp = dp[i - w - 1][j] + day[i].buyPrice * j;
				while (q.empty() == 0 && temp > q.back().val)	q.pop_back();
				q.push_back(Node(temp, j));
				while (q.empty() == 0 && j - q.front().day > day[i].buyMax)	q.pop_front();
				dp[i][j] = max(dp[i][j], q.front().val - day[i].buyPrice * j);
			}
			while (q.empty() == 0)	q.pop_back();
			for (int j = maxn; j >= 0; --j) {
				temp = dp[i - w - 1][j] + day[i].sellPrice * j;//有可能出现之前的状态不存在
				while (q.empty() == 0 && temp > q.back().val)	q.pop_back();
				q.push_back(Node(temp, j));
				while (q.empty() == 0 && q.front().day - j > day[i].sellMax)	q.pop_front();
				dp[i][j] = max(dp[i][j], q.front().val - day[i].sellPrice * j);
			}
		}

		int ans = 0;
		for (int i = 0; i <= maxn; ++i)
			ans = max(ans, dp[t][i]);
		cout << ans << '\n';
	}
}
