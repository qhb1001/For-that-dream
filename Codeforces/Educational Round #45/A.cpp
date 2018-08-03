#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, m, a, b;
	cin >> n >> m >> a >> b;
	if (n % m == 0) {
		cout << 0 << endl;
		return 0;
	}

	long long t = n / m;
	//to delete some boxes
	long long res = n % m;
	long long ans = res * b;

	//to create some boxes
	res = (t + 1) * m - n;
	ans = min(ans, res * a);
	cout << ans << endl;
	return 0;
}
