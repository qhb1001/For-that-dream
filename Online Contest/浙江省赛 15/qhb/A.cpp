#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
const int MAX = 1e5 + 5;
ll a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		ll Max = 0;
		int idx;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (Max < a[i])	Max = a[i], idx = i;
		}

		if (idx == 1 || idx == n) {
			cout << "No\n";
			continue;
		}
		bool flag = 1;
		for (int i = 2; i <= idx; ++i)	
			if (a[i] <= a[i - 1])	{
				flag = 0;
				break;
			}

		for (int i = idx + 1; i <= n; ++i) 
			if (a[i] >= a[i - 1]) {
				flag = 0;
				break;
			}

		cout << (flag? "Yes\n":"No\n");
	}
}
