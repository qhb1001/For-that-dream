#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sock[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> sock[i];
	//sort(sock + 1, sock + 1 + n);
	ll ans = 0, now;

	for (int i = n; i >= 2; --i) {
		sort(sock + 1, sock + 1 + i);
		ans += sock[i - 1];
		sock[i] -= sock[i - 1];
		sock[i - 1] = 1LL << 50;
		sort(sock + 1, sock + 1 + i);
	}
	cout << ans << endl;
}
