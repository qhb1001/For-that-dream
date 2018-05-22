#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int len = n >> 1;
	for (int i = 1; i <= len; ++i)	cin >> a[i];
	sort(a + 1, a + 1 + len);
	int ans1 = 0;//表示移到偶数位
	int now = 2;
	for (int i = 1; i <= len; ++i) {
		ans1 += abs(a[i] - now);
		now += 2;
	}

	int ans2 = 0;
	now = 1;
	for (int i = 1; i <= len; ++i) {
		ans2 += abs(a[i] - now);
		now += 2;
	}

	cout << min(ans1, ans2) << endl;
}
