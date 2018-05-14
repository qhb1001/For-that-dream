#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct Node {
	int a, b;
}a[5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Max = 0, num = 0;
	for (int i = 1; i <= 3; ++i) {
		cin >> a[i].a >> a[i].b;
		if (a[i].a > Max)	{
			Max = a[i].a;
			num = 1;
		} else if (a[i].a == Max)	{
			++num;
		}

		if (a[i].b > Max) {
			Max = a[i].b;
			num = 1;
		} else if (a[i].b == Max) {
			++num;
		}
	}

	if (num == 3) {
		int sum = 0;
		for (int i = 1; i <= 3; ++i) {
			if (a[i].a == a[i].b && a[i].a == Max)	{
				cout << "NO\n";
				return 0;
			}
			if (a[i].a != Max)	sum += a[i].a;
			if (a[i].b != Max)	sum += a[i].b;
		}

		if (sum != Max) {
			cout << "NO\n";
			return 0;
		} else {
			cout << "YES\n";
			return 0;
		}
	} else if (num == 1) {
		int x, idx;//最大边附带的小边
		int t[5];//其余的四条边
		bool flag = 0;
		for (int i = 1; i <= 3; ++i) {
			if (a[i].a == Max) {
				x = a[i].b;
				idx = i;
				break;
			} 
			if (a[i].b == Max) {
				x = a[i].a;
				idx = i;
				break;
			}
		}

		int cnt = 1;
		for (int i = 1; i <= 3; ++i)
			if (i != idx) {
				t[cnt++] = a[i].a;
				t[cnt++] = a[i].b;
			}

		if (t[1] + t[3] == Max && t[2] == t[4] && t[2] + x == Max)	flag = 1;
		if (t[1] + t[4] == Max && t[2] == t[3] && t[2] + x == Max)	flag = 1;
		if (t[2] + t[3] == Max && t[1] == t[4] && t[1] + x == Max)	flag = 1;
		if (t[2] + t[4] == Max && t[1] == t[3] && t[1] + x == Max)	flag = 1;

		if (flag)	cout << "YES\n";
		else	cout << "NO\n";
		return 0;
	}

	cout << "NO\n";
	return 0;
}
