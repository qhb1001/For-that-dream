#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double a, b;
	cin >> n >> m >> k;
	double Max = -(1<<30), idx;
	for (int i = 1; i <= k; ++i) {
		cin >> a >> b;
		if (a*m/n + b*(1-m/n) > Max) {
			Max = a*m/n + b*(1-m/n);
			idx = i - 1;
		}
	}

	cout << idx << " " << n << endl;

}
