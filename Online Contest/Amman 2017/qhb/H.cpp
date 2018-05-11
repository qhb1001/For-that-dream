#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void out(int x, int times) {
	for (int i = 1; i <= times; ++i)	cout << x;
}
int main() {
	freopen("input", "r", stdin);
	freopen("output.a", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		if (n == 1) {
			if (k >= 10)	cout << -1 << '\n';
			else	cout << k << '\n';
			continue;
		}

		//如果根本凑不出来这个和
		if (k < 2 || k > 9 * n)	{
			cout << -1 << '\n';
			continue;
		}

		int nine = k / 18, res = k % 18;
		//如果全都是9
		if (nine == n) {
			for (int i = 1; i <= n; ++i)	cout << 9;
			cout << '\n';
			continue;
		}

		//如果余数在中间
		if (n - nine == 1) {
			out(9, nine);
			cout << res;
			out(9, nine);
			cout << '\n';
			continue;
		}

		if (res&1) {//余数为奇数
			if ((n&1) == 0) {//长度为偶数
				cout << -1 << '\n';
				continue;
			} else {//必定是9 - res - 0 - 1 - 0 - res - 9的形式
				int halfN = (n - 1) / 2;
				out(9, nine);
				cout << (res - 1) / 2;
				out(0, halfN - 1 - nine);
				cout << 1;
				out(0, halfN - 1 - nine);
				cout << (res - 1) / 2;
				out(9, nine);
				cout << '\n';
				continue;
			}
		} else {//余数为偶数
			out(9, nine);
			cout << res / 2;
			out(0, n - 2 * (nine + 1));
			cout << res / 2;
			out(9, nine);
			cout << '\n';
			continue;
		}


	}
}
