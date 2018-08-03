#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 2e5 + 5;
int n, K;
map<int, int> mp;
struct Node {
	int num, times;
}a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> K;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		mp[t]++;
	}
	int cnt = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		a[++cnt].num = it->first;
		a[cnt].times = it->second;
	}


	int ans = n;
	for (int i = 2; i <= cnt; ++i) {
		if (a[i].num - a[i - 1].num <= K) {
			ans -= a[i - 1].times;
		}
	}

	cout << ans << endl;

}
