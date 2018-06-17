#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
ll a[MAX], b[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	for (int j = 1; j <= n; ++j)	cin >> b[j];
	ll temp;
	for (int i = 1; i <= n; ++i) {
		temp = min(a[i], b[i]);
		a[i] -= temp;
		b[i] -= temp;
	}
	int l = 1, r = 1;
	ll ans = 0;
	while (true) {
		while (l != n + 1 && a[l] == 0)	++l;
		while (r != n + 1 && b[r] == 0)	++r;
		if (l == n + 1 || r == n + 1)	break;
        //如果只需要移动到左边
        if (l >= r) {
            if (a[l] < b[r]) {
                ans += a[l] * (l - r);
                b[r] -= a[l];
                a[l] = 0;
            } else {
                ans += b[r] * (l - r);
                a[l] -= b[r];
                b[r] = 0;
            }
            continue;
        }
		if (a[l] < b[r]) {
			ans += a[l] * (l - 1) + a[l] * (r - 1);
			b[r] -= a[l];
			a[l] = 0;
		} else {
			ans += b[r] * (l - 1) + b[r] * (r - 1);
			a[l] -= b[r];
			b[r] = 0;
		}
	}

	cout << ans << '\n';
}
