#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
const int MAX = 1e5 + 5;
typedef long long ll;
ll a[MAX], b[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	for (int i = 1; i <= n; ++i)	cin >> b[i];
	int l = n, r = n;
	ll ans = 0, temp;
	while (true) {
		while (l != 0 && a[l] == 0)	--l;
		while (r != 0 && b[r] == 0)	--r;
		if (l == 0 || r == 0)	break;
		if (l >= r) {
			temp = min(a[l], b[r]);
			ans += temp * (l - r);
			a[l] -= temp;
			b[r] -= temp;
		} else {
			a[1] += a[l];
			ans += a[l] * (l - 1);
			a[l] = 0;
			--r;
		}
	}

	for (int i = 1; i <= n; ++i)	ans += b[i] * (i - 1);
	cout << ans << endl;

}
