#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int ll;
int n;
const ll MOD = 1e9 + 7;
const ll MAX = 1e6 + 5;
int a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin >> n) {
		for(int i = 0; i < n; ++i)	{
			cin >> a[i];
			a[i] %= MOD;
		}
		ll ans = (1 + a[n - 1] + a[n - 2] + 1LL * a[n - 1] * a[n - 2] % MOD) % MOD;
		cout << ans << endl;
	}
}
