#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
ll a[MAX], n, k, l, N, len = 1;
void getLen() {
	sort(a + 1, a + 1 + n * k);
	for (int i = 2; i <= N; ++i) {
		if (a[i] - a[1] <= l)	++len;
		else	return ;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> l;
	N = n*k;
	for (int i = 1; i <= N; ++i)	cin >> a[i];

	getLen();
	ll ans = 0;
	if (len < n)	{
		cout << 0 << endl;
		return 0;
	}
	int cnt = 0, ok = 0;
	for (int i = N; i >= 1; --i) {
		++cnt;
		if (cnt >= k && a[i] - a[1] <= l)	{
			cnt -= k;
			ans += a[i];
			++ok;
		}
		if (ok == n)	break;
	}
	cout << ans << endl;
}
