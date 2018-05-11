#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[10], ans;
const ll MOD = 1e9 + 7;
void init() {
	for (int i = 0; i <= 9; ++i)	a[i] = 0;
	ans = 0;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, now;
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &now);
			for (int j = now + 1; j <= 9; ++j) ans += a[j];
			a[now]++;
		}
		printf("%lld\n", ans % MOD);
	}
}
