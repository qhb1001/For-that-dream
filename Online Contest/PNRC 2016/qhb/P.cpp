#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int t[MAX<<1], n;
void build() {
	for (int i = n - 1; i > 0; --i)
		t[i] = t[i<<1] + t[i<<1|1];
}
void update(int p) {
	for (++t[p += n]; p > 1; p >>= 1) {
		t[p>>1] = t[p] + t[p^1];
	}
}
int query(int l, int r) {
	int ans = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)	ans += t[l++];
		if (r&1)	ans += t[--r];
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, r, now;
	cin >> n >> k >> r;
	for (int i = 0; i < k; ++i) {
		cin >> now;
		t[now + n - 1] = 1;
	}

	build();
	int ans = 0;
	for (int i = 0; i <= n - r; ++i) {
		now = query(i, i + r);
//		cout << now << " ";
		if (now >= 2)	continue;
		else if (now == 1) {
			if (t[i + r - 1 + n] == 0)	update(i + r - 1);
			else	update(i + r - 2);
			++ans;
		} else {
			update(i + r - 1);
			update(i + r - 2);
			ans += 2;
		}
	}

	cout << ans << endl;
}
