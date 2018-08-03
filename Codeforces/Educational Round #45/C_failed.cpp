#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <map>
using namespace std;
const int MAX = 3e5 + 5;
int n;
stack<int>s;
struct Node {
	int l, r;
	Node(int l = 0, int r = 0) {
		this->l = l;
		this->r = r;
	}
	bool operator < (const Node b) const {
		if (l != b.l)	return l < b.l;
		return r < b.r;
	}
};
typedef long long ll;
map<Node, ll>mp;
int update(string &t) {
	int l = 0, r = 0, len = t.size();
	for (int i = 0; i < len; ++i) {
		if (t[i] == '(')	++l;
		else {
			if (l)	--l;
			else	++r;
		}
	}
	mp[Node(l, r)]++;
	if (l == 0 && r == 0)	return 0;
	return mp[Node(r, l)];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string in;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> in;
		ans += update(in);
	}

	ans += mp[Node(0, 0)] * mp[Node(0, 0)];
	cout << ans << endl;
}
