#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 1e5 + 5;
int a[MAX], ans[MAX];
int main() {
	ios::sync_with_stdio(false);
	int n, len;
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	if (n&1)	len = (n + 1) / 2;
	else	len = n / 2;

	for (int i = 1; i <= len; ++i) {
		ans[a[i] - i + 1]++;
	}
	if (n&1)	len--;
	for (int i = 1; i <= len; ++i)
		ans[a[n - i + 1] - i + 1]++;

	int maxVal, maxAns = -1;
	for (int i = 1; i < MAX; ++i)
		if(ans[i] > maxAns)	{
			maxAns = ans[i];
			maxVal = i;
		}

	cout << n - maxAns << endl;

}
