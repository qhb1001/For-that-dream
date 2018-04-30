#include <iostream>
#include <cmath>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int c1, c2, n, m, v;
int lower(int *a, int x, int Max) {
	if (x < a[1])	return -1;

	int mid, l = 1, r = Max;
	while (l < r) {
		mid = (l + r) >> 1;
		if (a[mid] <= x)	l = mid + 1;
		else	r = mid - 1;
	}

	int ans = (l + r) >> 1;
	for (int i = 3; i >= -3; --i) {
		if (ans + i <= Max && ans + i >= 1) {
			if(a[ans + i] <= x)	return a[ans + i];
		}
	}
}

int upper(int *a, int x, int Max) {
	if (x > a[Max])	return -1;

	int mid, l = 1, r = Max;
	while (l < r) {
		mid = (l + r) >> 1;
		if (a[mid] >= x)	r = mid - 1;
		else	l = mid + 1;
	}

	int ans = (l + r) >> 1;
	for (int i = -3; i <= 3; ++i) {
		if (ans + i <= Max && ans + i >= 1) {
			if (a[ans + i] >= x)	return a[ans + i];
		}
	}
}
int stair[MAX], elevator[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> c1 >> c2 >> v;
	for (int i = 1; i <= c1; ++i)	cin >> stair[i];
	for (int i = 1; i <= c2; ++i)	cin >> elevator[i];
	sort(stair + 1, stair + 1 + c1);
	sort(elevator + 1, elevator + 1 + c2);
	int q;
	cin >> q;
	int floor1, x1, floor2, x2;
	while(q--) {
		cin >> floor1 >> x1 >> floor2 >> x2;
		if (floor1 == floor2) {
			cout << abs(x1 - x2) << '\n';
			continue;
		}

		int dfloor = abs(floor1 - floor2);
		if (x1 > x2)	swap(x1, x2);
		//首先使用电梯
		//从中间走
		int ans = 1<<30, sum = 0, now;
		int useElevator;
		if (dfloor % v == 0)	useElevator = dfloor / v;
		else	useElevator = dfloor / v + 1;
		now = lower(elevator, x2, c2);
		if (now != -1 && now >= x1) {
			ans = min(ans, x2 - x1 + useElevator);
		}
		//从右边走
		now = upper(elevator, x2, c2);
		if (now != -1) {
			ans = min(ans, x2 - x1 + 2 * (now - x2) + useElevator);
		}
		//cout << elevator[1] << " " << now << " " << ans << endl;
		//从左边走
		now = lower(elevator, x1, c2);
		if (now != -1) {
			ans = min(ans, x2 - x1 + 2 * (x1 - now) + useElevator);
		}

		//使用楼梯
		//从中间走
		now = lower(stair, x2, c1);
		if (now != -1 && now >= x1) {
			ans = min(ans, dfloor + x2 - x1);
		}
		//从右边走
		now = upper(stair, x2, c1);
		if (now != -1) {
			ans = min(ans, dfloor + x2 - x1 + 2 * (now - x2));
		}
		//从左边走
		now = lower(stair, x1, c1);
		if (now != -1) {
			ans = min(ans, dfloor + x2 - x1 + 2 * (x1 - now));
		}
		cout << ans << '\n';
	}

}

/*
5 6 1 1 1
1
6
1
1 2 1 4
*/
