#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
string s;
const int MAX = 1e6 + 5;
struct Node {
	int l, r, ans;
	Node(int a = 0, int b = 0, int c = 0): l(a), r(b), ans(c) {}
}t[MAX * 2];
int n;
Node combine(Node& a, Node& b) {
	int add = min(a.l, b.r);
	return Node(a.l - add + b.l, b.r - add + a.r, a.ans + b.ans + add); 
}
void build(int n) {
	for (int i = n - 1; i > 0; --i)
		t[i] = combine(t[i<<1], t[i<<1|1]);
}
Node query(int l, int r) {
	Node L, R;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)	L = combine(L, t[l++]);
		if (r&1)	R = combine(t[--r], R);
	}
	return combine(L, R);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			t[i + n] = Node(1, 0, 0);
		else	
			t[i + n] = Node(0, 1, 0);
	}
	build(n);

	int k, l, r;
	Node ans;
	cin >> k;
	while (k--) {
		cin >> l >> r;
		ans = query(l - 1, r);
		cout << ans.ans * 2 << '\n';
	}
}
