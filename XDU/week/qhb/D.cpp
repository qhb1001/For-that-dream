#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[60];
int main() {
	int T;
	cin >> T;
	while (T--) {
		ll sum;
		cin >> sum;
		int cnt = 0;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= 60; ++i) {
			ll now = 1LL<<cnt++;
			if (sum <= now)	{
				a[i] = sum;
				break;
			} else {
				a[i] = now;
				sum -= now;
			}
		}

		ll ansSum = 1;
		int ansIdx = 1;
		for (int i = 2; i < 60; ++i)
			if (a[i] > ansSum) {
				ansSum = a[i];
				ansIdx = i;
			}
		cout << ansIdx << " " << ansSum << '\n';
	}
}
