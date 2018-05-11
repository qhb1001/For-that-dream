#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b == 0? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
ll a[2005];
const ll MAX = 2e12;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)	cin >> a[i];
		ll ans = 0;
		for (int i = 1; i <= n; ++i){//枚举起点
			ll sum = a[i], common = a[i];
			++ans;
			for (int j = i + 1; j <= n; ++j) {
				sum += a[j];
				common = lcm(common, a[j]);
				//if (j == 3)	cout << i << " " << common << " " << sum << endl;
			//	if (i == 1 && j == 3) {
			//		cout << sum << " " << common << endl;
			//		cout << sum % common << endl;
			//	}
				if (sum % common == 0)	++ans;
				if (common > MAX)	break;
			}
		}

		cout << ans << '\n';
	}
}
