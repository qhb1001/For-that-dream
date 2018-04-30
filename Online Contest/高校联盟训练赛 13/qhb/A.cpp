#include <iostream>
#include <cstdio>
#include <cstring>
const int MAX = 1005;
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, T, l, a, tMax, tMin;
	cin >> T;
	while (T--) {
		cin >> l >> n;
		int ansMin = -1, ansMax = -1;
		for (int i = 1; i <= n; ++i) {
			cin >> a;
			tMax = max(a, l + 1 - a);
			tMin = min(a, l + 1 - a);
//			cout << tMax << endl;
			ansMin = max(ansMin, tMin);
			ansMax = max(ansMax, tMax);
		}

		cout << ansMin << " " << ansMax << '\n';
	}

}
