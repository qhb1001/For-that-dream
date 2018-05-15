#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a;
	cin >> a;
	a++;
	if (a == 1)	{
		cout << 0 << endl;
		return 0;
	}
	if (a&1)	cout <<a << endl;
	else	cout << a / 2 << endl;
}
