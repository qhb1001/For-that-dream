#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e4 + 5;
int t[MAX], n;
void build() {
	for (int i = n - 1; i > 0; --i)
		t[i] = min(t[i<<1], t[i<<1|1]);
}
int query(int l, int r) {
	int ans = 1<<30;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1)	ans = min(ans, t[l++]);
		if (r&1)	ans = min(ans, t[--r]);
	} 
	return ans;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%d", &t[i + n]);
		build();
		int ans = -(1<<30);
		for (int i = 1; i < n; ++i) {
			ans = max(ans, t[n + i] - query(i + 1, n + 1));
//			cout << query(i + 1, n + 1) << "~\n";
		}
		printf("%d\n", ans);
	}
}
