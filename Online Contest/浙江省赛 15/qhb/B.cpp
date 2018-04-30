#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e5 + 5;
int a[MAX], b[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
			a[i] = a[i] - b[i];
		}

		sort(a + 1, a + 1 + n);
		int ans = 1, now = 1;
		for (int i = 2; i <= n; ++i) 
			if (a[i] == a[i - 1])	++now;
			else	{
				ans = max(ans, now);
				now = 1;
			}
		ans = max(ans, now);
		cout << ans << '\n';
	}
}
