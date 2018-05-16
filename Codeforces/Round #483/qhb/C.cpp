#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
ull gcd(ull a, ull b) {
	return b == 0? a : gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		unsigned long long p, q, b;
		cin >> p >> q >> b;

		if (p == 0) {
			cout << "Finite\n";
			continue;
		}
		ull t = gcd(p, q);
		q /= t;
		t = gcd(q, b);
		while (t != 1) {
			while (q % t == 0)	q /= t;
			t = gcd(q, b);
		}
		
		if (q == 1)	cout << "Finite\n";
		else	cout << "Infinite\n";
	}
}
