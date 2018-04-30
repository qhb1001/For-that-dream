#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int number[10];
void deal(int x) {
	for (int i = 5; i >= 1; --i) {
		number[i] = x % 10;
		x /= 10;
	}
}
int one() {
	return number[1] * 100 + number[2] * 10 + number[3];
}
int two() {
	return number[2] * 100 + number[3] * 10 + number[4];
}
int three() {
	return number[3] * 100 + number[4] * 10 + number[5];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	while (cin >> k) {
		for (int i = 10000; i <= 30000; ++i) {
			deal(i);
			if (one() % k == 0 && two() % k == 0 && three() % k == 0)	cout << i << '\n';
		}
	}
}
