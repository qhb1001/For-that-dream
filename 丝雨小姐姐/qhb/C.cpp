#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int MAX = 1e5 + 5;
int n, m, k, a[MAX];
void in() {
	for (int i = 1; i <= n; ++i)	cin >> a[i];
}
struct Node {
	int idx, val;
	Node(int a = 0, int b = 0): idx(a), val(b) {}
}now;
int deal() {
	deque<Node>Max, Min;
	queue<Node>q;
	int ans = 0, temp;
	for (int i = 1; i <= n; ++i) {
		//维护两个单调队列的单调性
		now = Node(i, a[i]);
		while (Max.empty() == 0 && a[i] >= Max.back().val)	Max.pop_back();
		Max.push_back(now);
		while (Min.empty() == 0 && a[i] <= Min.back().val)	Min.pop_back();
		Min.push_back(now);
		q.push(now);
		//查看是否越界
		temp = Max.front().val - Min.front().val;
		if (temp < m)	continue;
		if (temp >= m && temp <= k)	{
			ans = max(ans, (int)q.size());
			continue;
		}

		while (true) {
			now = q.front(); q.pop();
			if (now.idx == Max.front().idx)	Max.pop_front();
			if (now.idx == Min.front().idx)	Min.pop_front();
			temp = Max.front().val - Min.front().val;
			if (temp >= m && temp <= k)	{
				ans = max(ans, (int)q.size());
				break;
			} else if (temp < m) break;
			if (q.empty() == 1)	break;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m >> k) {
		in();
		cout << deal() << '\n';
	}
}
