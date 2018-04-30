#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 105;
int a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s, hour, minu;
	cin >> n >> s;
	
	for (int i = 1; i <= n; ++i)	{
		cin >> hour >> minu;
		a[i] = hour * 60 + minu;
	}

	sort(a + 1, a + 1 + n);

	if (s + 1 <= a[1]) {
		cout << "0 0\n";
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i + 1] - a[i] >= 2 * s + 2) {
			int ans = a[i] + s + 1;
			cout << ans / 60 << " " << ans % 60 << endl;
			return 0;
		}
	}

	int ans = a[n] + s + 1;
	cout << ans / 60 << " " << ans % 60 << endl;
	return 0;

}
