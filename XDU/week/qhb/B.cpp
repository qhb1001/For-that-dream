#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
long long a[3000];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long n, k;
		scanf("%lld%lld", &n, &k);
		k = n * (n - 1) / 2 - k + 1;
		for (int i = 1; i <= n; ++i)	scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		long long sum = n - 1, cnt = n - 2;
		for (int i = 1; i <= n; ++i) {
//			cout << sum << " " << k << endl;
			if (sum >= k) {
				printf("%lld\n", a[i]);
				break;
			}
			sum += cnt--;
		}
	}
}
