#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 10005;
typedef long long ll;
ll n, m, idx[MAX], now, sum;
ll max(ll a, ll b) {
	if(a > b)	return a;
	return b;
}
int main() {
	//freopen("input", "r", stdin);
	//freopen("output.a", "w", stdout);
	while(scanf("%lld%lld", &n, &m) != EOF) {
		ll ans = -1;
		memset(idx, 0, sizeof(idx));
		sum = 0;
		for(ll i = 1; i <= n; ++i) {
			scanf("%lld", &now);
			sum += now;
			sum %= m;
			sum = (sum + m) % m;

			if(idx[sum] == 0)	idx[sum] = i;
			else	ans = max(ans, i - idx[sum]);
			if(sum == 0)	ans = max(ans, i);
		}

		if(ans == -1)	ans = 0;
		cout << ans << endl;
	}
}
