#include <iostream>
#include <stack>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
stack<int>s[MAX];
struct Node {
	int val, idx;
	bool operator < (const Node b) const {
		return idx < b.idx;
	}
}t[MAX];
int a[MAX];
priority_queue<Node>q;
void deal(int n) {
	sort(t + 1, t + 1 + n, [](Node a, Node b) {
			return a.val < b.val;
			});
	int cnt = 1;
	a[t[1].idx] = 1;
	for (int i = 1; i <= n; ++i) {
		if (t[i].val == t[i - 1].val) {
			a[t[i].idx] = cnt;
		} else {
			a[t[i].idx] = ++cnt;
		}
	}

	for (int i = 1; i < MAX; ++i)
		while (s[i].empty() == 0)	s[i].pop();
}
bool vis[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	freopen("input", "r", stdin);
	freopen("output.b", "w", stdout);
	cin >> T;
	while (T--) {
		while (q.empty() == 0)	q.pop();
		int n, k;
		cin >> n >> k;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; ++i) {
			cin >> t[i].val;
			t[i].idx = i;
		}

		deal(n);//离散化完毕

		if (k >= n) {
			int ans = 0;
			for (int i = 1; i <= n; ++i)
				if (vis[a[i]])	continue;
				else {
					++ans;
					vis[a[i]] = 1;
				}
			cout << ans << '\n';
			continue;
		}
		for (int i = n; i >= 1; --i)
			s[a[i]].push(i);//对于该元素，推入其下标

		Node tempNode;
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (vis[a[i]])	continue;
			++ans;
			if (q.size() != k) {
				//因为每次遇到这个元素的时候，栈中必定存有这个位置的下标，所以首先弹出
				//同时，这也是我需要维护的一个性质
				s[a[i]].pop();
				if (s[a[i]].size() == 0) {//如果该元素在后面不再出现了
					tempNode.idx = 1<<30;
					tempNode.val = a[i];
					q.push(tempNode);
					vis[a[i]] = 1;
				} else {
					tempNode.idx = s[a[i]].top();
					tempNode.val = a[i];
					q.push(tempNode);
					vis[a[i]] = 1;
				}
			} else {
				tempNode = q.top();
				vis[tempNode.val] = 0;
				q.pop();
				s[a[i]].pop();
				tempNode.val = a[i];
				vis[a[i]] = 1;
				if (s[a[i]].size() == 0) {
					tempNode.idx = 1<<30;
				} else {
					tempNode.idx = s[a[i]].top();
				}
				q.push(tempNode);
			}
		}
		cout << ans << '\n';
	}
}
