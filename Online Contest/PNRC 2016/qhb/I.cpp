#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long temp, Max = 0, sum = 0;
	cin >> n;
	while (n--) {
		cin >> temp;
		Max = max(temp, Max);
		sum += temp;
	}

	if (2 * Max <= sum)	cout << sum / 2 << endl;
	else cout << sum - Max << endl;
}
