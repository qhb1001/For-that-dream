#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 3e5 + 5;
int n;
pair<double, int>a[MAX];
void out(int l, int r) {
	for (int i = l; i <= r; ++i)
		cout << a[i].second << " ";
	cout << '\n';
}
bool deal(double x1, double x2, bool flag) {
	for (int i = n; i > 1; --i) {
		if (a[i].first >= x2 / (n - i + 1)) {//如果后n - i + 1个元素可以满足较大值的需求
			int l = 1, r = i - 1, mid;
			while (l < r) {
				mid = (l + r) >> 1;
				if (a[mid].first >= x1 / (i - mid))	r = mid - 1;
				else	l = mid + 1;
			}

			mid = (l + r) >> 1;
			for (int j = -3; j <= 3; ++j) {
				if (mid + j >= 1 && mid + j < i
					&& a[mid + j].first >= x1 / (i - (mid + j))) {
					int ans = mid + j;
					cout << "Yes\n";
					if (!flag) {
						cout << i - ans << " " << n - i + 1 << '\n';
						out(ans, i - 1);
						out(i, n);
					} else {
						cout << n - i + 1 << " " << i - ans << '\n';
						out(i, n);
						out(ans, i - 1);
					}
					return true;
				}
			}
			return false;
		}
	}
	return false;
}
double x1, x2;
int main() {
	freopen("input", "r", stdin);
	freopen("output.b", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x1 >> x2;
	for (int i = 1; i <= n; ++i)	{
		cin >> a[i].first;
		a[i].second = i;
	}
	bool flag;
	//令x2为大值，falg进行标记，为了之后的输出
	if (x1 > x2)	{swap(x1, x2); flag = 1;}
	else	flag = 0;

	sort(a + 1, a + 1 + n);
	if (deal(x1, x2, flag)) return 0;
	if (flag)	swap(x1, x2);

	if (x2 > x1) {swap(x1, x2); flag = 1;}
	else 	flag = 0;
	if (deal(x1, x2, flag)) return 0;


	cout << "No\n";
}
