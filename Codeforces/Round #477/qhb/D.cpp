#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 3e5 + 5;
int n;
pair<double, int>a[MAX];
bool deal(double x1, double x2, bool flag) {
	for (int i = n; i > 1; --i) {
		if (a[i].first >= x2 / (n - i + 1)) {//如果后n - i + 1个元素可以满足较大值的需求

			for (int j = 1; j < i; ++j) {
				if (a[j].first >= x1 / (i - j)) {
					cout << "Yes\n";
					if (!flag) {
						cout << i - j << " " << n - i + 1 << '\n';
						for (int k = j; k < i; ++k)
							cout << a[k].second << " ";
						cout << '\n';
						for (int k = i; k <= n; ++k)
							cout << a[k].second << " ";
						cout << '\n';
					} else {
						cout << n - i + 1 << " " << i - j << '\n';
						for (int k = i; k <= n; ++k)
							cout << a[k].second << " ";
						cout << '\n';
						for (int k = j; k < i; ++k)
							cout << a[k].second << " ";
						cout << '\n';
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input", "r", stdin);
	freopen("output.a", "w", stdout);
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
