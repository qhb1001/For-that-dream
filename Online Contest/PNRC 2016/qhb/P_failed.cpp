#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int n, k, r, a[MAX], pre[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> r;
	for (int i = 1; i <= k; ++i) {
		int now;
		cin >> now;
		a[now] = 1;
	}

	for (int i = 1; i <= n; ++i)	pre[i] = pre[i - 1] + a[i];

	int now, ans = 0;
	for (int i = 1; i <= n - r + 1; ++i) {
		now = pre[i + r - 1] - pre[i - 1];
		if (now >= 2)	continue;
		//对i + r - 1位置添加摄像头，如果该位置不是摄像头的话
		if (now == 1) {
			if (a[i + r - 1] == 0)	{
				a[i + r - 1] = 1;
				++ans;
				i = i + r - 1;
			} else {
				a[i + r - 2] = 1;
				++ans;
				i = i + r - 1;
			}
		} else {
			a[i + r - 1] = a[i + r - 2] = 1;
			ans += 2;
			i = i + r - 1;
		}
	}

	cout << ans << endl;
}
