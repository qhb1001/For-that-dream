#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int val, idx;
	bool operator < (const Node& b) const {
		if(val != b.val)
			return val > b.val;
		return idx < b.idx;
	}
}tempNode;
vector<Node>q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n) {
		q.clear();
		for(int i = 0; i < n; ++i) {
			cin >> tempNode.val;
			tempNode.idx = i;
			q.push_back(tempNode);
		}

		sort(q.begin(), q.end());
		stack<Node>s[1005];
		int IdxofStack = 0, j;
		s[0].push(q[0]);
		IdxofStack = 1;
		for(int i = 1; i < n; ++i) {
			for(j = 0; j < IdxofStack; ++j)
				if(q[i].idx > s[j].top().idx && q[i].val < s[j].top().val) {
					s[j].push(q[i]);
					break;
				}
			if(j == IdxofStack) {
				s[IdxofStack++].push(q[i]);
			}
		}

		cout << IdxofStack << '\n';
	}
}
