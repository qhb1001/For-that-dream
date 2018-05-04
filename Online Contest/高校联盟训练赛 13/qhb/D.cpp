#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int now[500], final[500];
int n, c, k;
int deal(int s, int t) {
	int now_color, l, r, ans = 0;
	while (true) {
		l = s;
		while (now[l] == final[l] && l <= t)	++l;
		if (l > t)	break;//所有的颜色都匹配
		r = l;
		now_color = final[l];
		for (int i = l + 1; i <= t; ++i) {
			if (now[i] == final[i])	{
				break;
			}
			if (final[i] == now_color)	r = i;
		}
		
		//将[l, r]范围内染色为 now_color
		int len = 1 + r - l;
		if (len % k == 0)	ans += len / k;
		else	ans += len / k + 1;
		for (int i = l; i <= r; ++i)	now[i] = now_color;
	}

	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> c >> k;
		for (int i = 1; i <= n; ++i)	cin >> final[i];
		for (int i = 1; i <= n; ++i)	final[i + n] = final[i];

		int ans = 1<<30;
		for (int i = 1; i <= n; ++i) {
			memset(now, 0, sizeof(now));
			ans = min(ans, deal(i, i + n - 1));
		}
		cout << ans << '\n';
	}
}
