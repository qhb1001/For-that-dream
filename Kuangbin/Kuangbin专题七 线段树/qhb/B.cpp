#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 4e5 + 5;
int n, m, t[MAX];
void build() {
	for(int i = n - 1; i > 0; --i)	t[i] = max(t[i<<1], t[i<<1|1]);
}
void update(int x, int val) {
	for(t[x += n] = val; x > 1; x >>= 1) {// Note that 'x' can't be 1
		t[x>>1] = max(t[x], t[x^1]);
	}
}
int query(int l, int r) {
	int ans = -(1<<30);
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)	ans = max(ans, t[l++]);
		if(r&1)	ans = max(ans, t[--r]);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		for(int i = 0; i < n; ++i)	cin >> t[i + n];
		build();
		string type;
		int a, b;
		while(m--) {
			cin >> type >> a >> b;
			if(type[0] == 'Q')	cout << query(a - 1, b) << '\n';
			else	update(a - 1, b);
		}
	}
}
