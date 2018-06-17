#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 5;
int t[MAX<<1], n;
void update(int x) {
	for (t[x += n]++; x > 1; x >>= 1) {
		t[x>>1] = t[x] + t[x^1];
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

int a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != n)	ans += query(a[i] + 1, n + 1);
		// cout << ans << endl;
		update(a[i]);
	}

	// cout << ans << endl;

	if (n&1) {
		if (ans&1)	cout << "Petr";
		else	cout << "Um_nik";
	} else {
		if (ans&1)	cout << "Um_nik";
		else	cout << "Petr";
	}
	return 0;
}
