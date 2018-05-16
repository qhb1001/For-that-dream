#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);

	int Left = n, r = n, l = 1;
	while (true) {
		if (Left == 1)	break;
		--r; Left--;
		if (Left == 1)	break;
		++l; Left--;
		if (Left == 1)	break;
	}

	cout << a[l] << endl;
}
