#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
	int type, val;
}a[MAX];
bool check(Node a, Node b) { //是否 a < b
	if (a.type != b.type)	return a.type < b.type;
	return a.val < b.val;
}
int main() {
	freopen("input", "r", stdin);
	//freopen("output.a", "w", stdout);
	char c[2];
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, idx = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", c);
			if (c[0] == 'C')	a[i].type = 1;
			else if (c[0] == 'B')	a[i].type = 2;
			else if (c[0] == 'D')	a[i].type = 3;
			else	idx = i;
			if (c[0] != 'W')
				scanf("%d", &a[i].val);
		}

		if (n == 1)	{
			printf("%d\n", 3 * m);
			continue;
		}
		if (idx == 1) {
			printf("%d\n", (a[2].type - 1) * m + a[2].val - 1);
			continue;
		}
		if (idx == 2) {
			if (n == 2) {
				printf("%d\n", m - a[1].val + (3 - a[1].type) * m);
				continue;
			}
			if (check(a[1], a[3])) {
				printf("%d\n", (a[3].type - a[1].type) * m + a[3].val - a[1].val);
				continue;
			}
		}

		if (!check(a[1], a[2])) {
			printf("1\n");
			continue;
		}
		if (idx == 0)	{
			printf("%d\n", 3 * m - n + 1);
			continue;
		}
		if (idx == n) {
			printf("%d\n", (3 - a[n - 1].type) * m + m - a[n - 1].val);
			continue;
		}

		if (a[idx + 1].type == a[idx - 1].type) {
			printf("%d\n", a[idx + 1].val - a[idx - 1].val - 1);
			continue;
		}

		printf("%d\n", (a[idx + 1].type - a[idx - 1].type - 1) * m + m - a[idx - 1].val + a[idx + 1].val - 1);
	}
	return 0;
}
