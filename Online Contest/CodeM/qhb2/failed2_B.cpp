#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
ll a[MAX], b[MAX], ans;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	//尽量朝左走
	//该步骤结束之后，仅存的情况是a中元素都在b中元素左边
	while (true) {
		while (l != n + 1 && a[l] == 0)	++l;
		while (r != n + 1 && b[r] == 0)	++r;
		if (l == n + 1 || r == n + 1)	break;
		if (l < r) {
			if (l == 1) {
				++l;
				continue;
			}
			a[1] += a[l];
			a[l] = 0;
			continue;
		}
		temp = min(a[l], b[r]);
		a[l] -= temp;
		b[r] -= temp;
		ans += temp * (l - r);
	}

	for (int i = 1; i <= n; ++i)
		ans += a[i] * (i - 1);
	for (int i = 1; i <= n; ++i)
		ans += b[i] * (i - 1);

	cout << ans << '\n';
}
