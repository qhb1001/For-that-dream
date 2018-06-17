#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int ans[MAX];
int main() {
	int n;
	scanf("%d", &n);
	if (n % 4 >= 2)	return 0 * printf("-1\n");

	int a = 2, b = n, idx = 1;
	for (int i = 1; i <= n / 4; ++i) {
		ans[idx] = a;
		ans[idx + 1] = b;
		ans[n - idx + 1] = b - 1;
		ans[n - idx] = a - 1;
		a += 2;
		b -= 2;
		idx += 2;
	}

	if (n % 4)	ans[(n + 1) / 2] = (n + 1) / 2;
	
	for (int i = 1; i <= n; ++i)	printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
