#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const ll INF = 2e9;
ll sum(ll a) {
	return a * (a + 1) / 2;
}
ll n, H;
ll sum2(ll a) {
	return sum(a - 1) * 2 + a - sum(H - 1);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> H;
	if (H >= INF || sum(H) >= n) {//如果三角结构可以解决该题
		ll l = 1, r = H, mid;
		while (l < r) {
			mid = (l + r) >> 1;
			if (sum(mid) < n)	l = mid + 1;
			else	r = mid - 1;
		}

		ll Min = 1LL<<40;
		mid = (l + r) >> 1;
		ll ans;
		for (ll i = -5; i <= 5; ++i) {
			if (mid + i >= 1 && mid + i <= H) {
				if (abs(sum(mid + i) - n) <= mid + i) {
					if (sum(mid + i) - n >= 0)	ans = mid + i;
					else if (sum(mid + i) - n < 0)	ans = mid + i + 1;
					break;
				}
			}
		}

		cout << ans << endl;
		return 0;
	}

	ll l = H, r = INF, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (sum2(mid) < n)	l = mid + 1;
		else	r = mid - 1;
	}
	ll Min = 1LL<<40, ans;
	mid = (l + r) >> 1;
	for (ll i = -5; i <= 5; ++i) {
		if (mid + i >= H && mid + i <= INF) {
			if (abs(sum2(mid + i) - n) <= 2 * (mid + i) - H) {
				if (sum2(mid + i) - n >= 0)	 {
					ans = mid + i;
					cout << ans << endl;
					return 0;
				}
			}
			if (n - sum2(mid + i) <= mid + i) {
				cout << mid + i + 1 << endl;
				return 0;
			}
		}
	}
}
