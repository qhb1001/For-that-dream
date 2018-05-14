#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll p, s;
int n;
const int MAX = 2e4 + 5;
ll a[MAX];
bool check(ll x) {
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] <= x)	continue;
		sum += (a[i] - x) * p;
	}
	return sum <= s;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	cin >> p >> s;
	int l = 1, r = 2000;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))	r = mid - 1;
		else	l = mid + 1;
	}

	int ans = (l + r) >> 1;
	for (int i = -5; i <= 5; ++i) 
		if (i + ans >= 1 && i + ans <= 2000 && check(i + ans)) {
			cout << i + ans << endl;
			return 0;
		}
}
