#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
double s[MAX], pre[MAX], A, B;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> A >> B;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	sort(s + 2, s + 1 + n);
	for (int i = 2; i <= n; ++i)	pre[i] = pre[i - 1] + s[i];

	//第一个元素必须取，所以不必参与排序
	int l = 1, r = n;
	double sum;
	while (l < r) {
		int mid = (l + r) >> 1;
		sum = pre[mid] + s[1];
		if (s[1] * A / sum >= B)	l = mid + 1;
		else	r = mid - 1;
	}

	int ans = (l + r) >> 1;
	for (int i = 5; i >= -5; --i) {
		if (ans + i <= n && ans + i >= 1) {
			sum = pre[ans + i] + s[1];
			if (s[1] * A / sum >= B)	{
				ans = ans + i;
				break;
			}
		}
	}

	//cout << ans << endl;
	cout << n - ans << endl;
}
