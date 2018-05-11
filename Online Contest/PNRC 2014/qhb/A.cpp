#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		cout << 2 - a + b << endl;
	}
}
