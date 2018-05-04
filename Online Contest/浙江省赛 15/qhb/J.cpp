#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string a;
const int MAX = 1e5 + 5;
int ans[MAX], pre[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input", "r", stdin);
	//freopen("output.a", "w", stdout);
	int T, n;
	cin >> T;
	//for (int i = 1; i < MAX; ++i)	pre[i] = pre[i - 1] + i;
	while (T--) {
		cin >> n >> a;
		long long sum = 1LL * n * (n + 1) / 2;
		if (sum&1)	{
			cout << -1 << endl;
			continue;
		}

		sum /= 2;
		for (int i = n; i >= 1; --i) {
			if (sum >= i) {
				if (a[i - 1] == '0')	ans[i - 1] = 1;
				else	ans[i - 1] = 3;
				sum -= i;
			} else {
				if (a[i - 1] == '0')	ans[i - 1] = 2;
				else	ans[i - 1] = 4;
			}
		}

		for (int i = 0; i < n; ++i)	cout << ans[i];
		cout << '\n';
	}
}
