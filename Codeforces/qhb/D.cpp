#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
struct Node {
	ll val;
	int idx;
	Node(){}
	Node(ll a, int b) {
		val = a;
		idx = b;
	}
	bool operator < (const Node &b) const {
		if(val != b.val)	return val > b.val;
		return idx > b.idx;
	}
}tempNode, a, b;
int n;
const int MAX = 1e5 + 5e4 + 5;
ll ans[MAX];
priority_queue<Node>pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> tempNode.val;
		tempNode.idx = i;
		pq.push(tempNode);
	}

	while(true) {
		if(pq.size() >= 2) {
			a = pq.top();pq.pop();
			b = pq.top();pq.pop();
			if(a.val == b.val) {
				pq.push(Node(a.val * 2, b.idx));
			} else {
				ans[a.idx] = a.val;
				pq.push(b);
			}
		} else {
			a = pq.top();pq.pop();
			ans[a.idx] = a.val;
			break;
		}
	}

	int len = 0;
	for(int i = 1; i <= n; ++i)	if(ans[i])	++len;
	cout << len << '\n';
	for(int i = 1; i <= n; ++i)	if(ans[i])	cout << ans[i] << ' ';
	return 0;
}
