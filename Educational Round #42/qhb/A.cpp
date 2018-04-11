#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e5 + 5;
long long a[MAX];
long long sum = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}

	if(sum % 2)	sum = sum / 2 + 1;
	else	sum /= 2;
	for(int i = 1; i <= n; ++i) {
		a[i] = a[i - 1] + a[i];
		if(a[i] >= sum) {
			cout << i << endl;
			return 0;
		}
	}
}
