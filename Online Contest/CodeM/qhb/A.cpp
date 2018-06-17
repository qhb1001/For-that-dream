#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
const int MAX = 15;
struct Node {
	double val;
	bool ok;
}a[MAX];
int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	double n, m, sum = 0;
	cin >> n >> m;
	double Max1 = 0, Max2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].val >> a[i].ok;
		sum += a[i].val;
		if (a[i].ok)	Max1 += a[i].val * 0.2;
	}

	double tempa, tempb;
	for (int i = 1; i <= m; ++i) {
		cin >> tempa >> tempb;
		if (tempa <= sum)	Max2 = max(Max2, tempb);
	}

	printf("%.2lf\n", sum - max(Max1, Max2));
	return 0;
}
