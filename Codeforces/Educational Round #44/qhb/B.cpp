#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2005;
string a[MAX];
int row, col, times[MAX];
void getTimes() {
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < row; ++j)
			times[i] += a[j][i] - '0';
}

bool check() {
	bool flag;
	for (int i = 0; i < row; ++i) {
		flag = 1;
		for (int j = 0; j < col; ++j) {
			if (times[j] - (a[i][j] - '0') == 0)	{
				flag = 0;
				break;
			}
		}
		if (flag)	return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col;
	for (int i = 0; i < row; ++i)	cin >> a[i];

	getTimes();
	if (check())	cout << "YES\n";
	else	cout << "NO\n";
}
