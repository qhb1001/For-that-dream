#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
struct Node {
	int ans1, ans2;
	Node(int a = 0, int b = 0) {
		ans1 = a;
		ans2 = b;
	}
};
typedef long long ll;
map<ll, Node>mp;
const ll MAX = 2e5 + 5;
ll a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, n;
	ll sum;
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		sum = 0;
		cin >> n;
		for (int j = 1; j <= n; ++j) {
			cin >> a[j];
			sum += a[j];
		}

		for (int j = 1; j <= n; ++j) {
			sum -= a[j];
			if (mp.count(sum)) {
				cout << "YES\n";
				cout << mp[sum].ans1 << " " << mp[sum].ans2 << endl;
				cout << i << " " << j << endl;
				return 0;
			}
			sum += a[j];
		}

		for (int j = 1; j <= n; ++j) {
			sum -= a[j];
			mp[sum] = Node(i, j);
			sum += a[j];
		}
	}

	cout << "NO\n";
}
