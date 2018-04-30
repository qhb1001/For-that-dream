#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, b, a;
		bool flag = 0;
		cin >> n >> b;

		for (int i = 1; i <= n; ++i) {
			cin >> a;
			if ((a + b) % 7 == 0)	flag = 1;
		}
		if (flag)	cout << "Yes\n";
		else	cout << "No\n";
	}
}
