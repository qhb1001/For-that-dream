#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 105;
struct Node {
	string s;
	long long val;
	Node(string a = "", long long b = 0) :s(a), val(b){}
	bool operator < (const Node &b) const {
		if (val != b.val)	return val > b.val;
		return s < b.s;
	}
}a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].s >> a[i].val;
		}

		long long ans = 0;
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= m; ++i)	ans += (m - i + 1) * a[i].val;
		cout << ans;
		for (int i = 1; i <= m; ++i)	cout << " " <<  a[i].s;
		cout << '\n';
	}
}
