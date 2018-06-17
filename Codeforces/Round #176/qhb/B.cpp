#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll n, k;
ll binary1(ll now) {//find the rightmost value that less than 'now'
	ll l = 1, r = k, mid;
	while (l < k) {
		mid = (l + r) >> 1;
		if (now < mid)	r = mid - 1;
		else	l = mid + 1;
	}

	mid = (l + r) >> 1;
	for (ll i = 5; i >= -5; --i) {
		if (mid + i <= k && now >= mid + i) {
			return mid + i;
		}
	}
	return mid;
}
ll binary2(ll sum, ll now) {
	ll l = 1, r = now + 1, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if ((now + mid) * (now - mid + 1) / 2 > sum)	l = mid + 1;
		else	r = mid - 1;
	}

	mid = (l + r) >> 1;
	for (ll i = -5; i <= 5; ++i) {
		if (mid + i <= now && mid + i >= 1 && (now + mid + i) * (now - mid - i + 1) / 2 <= sum) {
			return mid + i;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	--n;
	if (k * (k - 1) / 2 < n)	 {
		cout << -1 << endl;
		return 0;
	}

	--k;

	ll ans = binary2(n, k);
	if ((k + ans) * (k - ans + 1) / 2 == n)	ans = k - ans + 1;
	else	ans = k - ans + 2;

	cout << ans << endl;
}
