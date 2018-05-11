#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
const int MAX = 1e5 + 5;
stack<int>Stack[MAX];
struct Node {
	int val, idx;
	bool operator < (const Node b) const {
		return idx > b.idx;
	}
}tempNode, t[MAX];
set<Node>Set;
int a[MAX];
void discrete(int n) {
	for (int i = 1; i <= n; ++i) {
		cin >> t[i].val;
		t[i].idx = i;
	}
	sort(t + 1, t + 1 + n, [](Node a, Node b) {
				return a.val < b.val;
			});
	int cnt = 1;
	a[t[1].idx] = 1;
	for (int i = 2; i <= n; ++i)
		if (t[i].val == t[i - 1].val)	a[t[i].idx] = cnt;
		else	a[t[i].idx] = ++cnt;

	for (int i = 1; i < MAX; ++i)
		while (Stack[i].size() != 0)	Stack[i].pop();
}
bool vis[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		Set.clear();
		discrete(n);
		memset(vis, 0, sizeof(vis));
		for (int i = n; i >= 1; --i)
			Stack[a[i]].push(i);

		int ans = 0;
		stack<int>toDelete;
		for (int i = 1; i <= n; ++i) {
			if (vis[a[i]]) {
				tempNode.idx = Stack[a[i]].top();
				Set.erase(Set.find(tempNode));
				tempNode.val = a[i];
				Stack[a[i]].pop();
				if (Stack[a[i]].size() == 0)	{
					toDelete.push(a[i]);
				} else {
					tempNode.idx = Stack[a[i]].top();
					Set.insert(tempNode);
				}
				continue;
			}
			++ans;
			if (toDelete.size() + Set.size() < k) {//需要一直插入元素
				Stack[a[i]].pop();
				tempNode.val = a[i];
				vis[a[i]] = 1;
				if (Stack[a[i]].size() == 0) {//如果之后不再存在
					toDelete.push(a[i]);
				} else {
					tempNode.idx = Stack[a[i]].top();
					Set.insert(tempNode);
				}
			} else {//首先删除元素，之后插入元素
				if (toDelete.size() != 0) {
					vis[toDelete.top()] = 0;
					toDelete.pop();
				} else {
					vis[Set.begin()->val] = 0;
					Set.erase(Set.begin());
				}

				//插入当前元素
				Stack[a[i]].pop();
				if (Stack[a[i]].size() != 0) {
					tempNode.idx = Stack[a[i]].top();
					tempNode.val = a[i];
					Set.insert(tempNode);
				} else {
					toDelete.push(a[i]);
				}
				vis[a[i]] = 1;
			}
		}

		cout << ans << '\n';
	}
}
