#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll n, k;
int main() {
	cin >> n >> k;
	--n;
	ll ans = 0;
	if (k * (k - 1) / 2 < n)	{
		cout << -1 << endl;
		return 0;
	}
	--k;
	while (n && k) {
		if (n >= k)	{
			n -= k;
			++ans;
		}
		--k;
	}
	if (ans == 0)	ans = -1;
	if (n)	ans = -1;
	cout << ans << endl;
}
