#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
ll a[MAX], ans, pre[MAX];
int main() {
	pre[1] = 1;
	for(int i = 2; i < MAX; ++i)	pre[i] = pre[i - 1] + i;
//	freopen("input", "r", stdin);
//	freopen("output.a", "w", stdout);
	int n;
	ll d;
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; ++i)	scanf("%lld", &a[i]);

	int l = 1, r = 3;

	if (n < 3)	{
		printf("0\n");
		return 0;
	}

	while (true) {
		if (r == n && r - l < 2)	break;
		else if (r - l < 2)	{
			++r;
			continue;
		}
		if (a[r] - a[l] <= d) {
			ans += pre[r - l - 1];
			if(r == n)	break;
			else	++r;
		} else {
			++l;
		}
	}

	printf("%lld\n", ans);
}
