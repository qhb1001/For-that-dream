#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int n, ans[MAX];
struct Node {
	int val, idx;
	bool operator < (const Node& b) const {
		return val < b.val;
	}
}a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n) {
		long long sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].val;
			a[i].idx = i;
			sum += a[i].val;
		}
		if (sum & 1)	{
			cout << "No\n";
			continue;
		}

		sort(a + 1, a + 1 + n);
		sum /= 2;
		for (int i = n; i >= 1; --i) {
			if (sum >= a[i].val)	ans[a[i].idx] = 1, sum -= a[i].val;
			else	ans[a[i].idx] = -1;
		}

		cout << "Yes\n" << ans[1];
		for (int i = 2; i <= n; ++i)	cout << " " << ans[i];
		cout << endl;
	}
}
