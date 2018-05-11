#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;
struct Node {
	double weight, value;
	bool operator < (const Node b) const {
		return value / weight > b.value / b.weight;
	}
	void in() {
		scanf("%lf%lf", &weight, &value);
	}
}a[1005];
int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	a[i].in();
		double sum, ans = 0;
		scanf("%lf", &sum);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; ++i) {
			if (a[i].weight <= sum) {
				ans += a[i].value;
				sum -= a[i].weight;
			} else {
				ans += sum * a[i].value / a[i].weight;
				break;
			}

		}
		printf("%.5lf\n", ans);
	}
}
