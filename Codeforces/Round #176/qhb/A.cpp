#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string G[5];
bool check(int x, int y) {
	int num = 0;
	num += (G[x][y] == '.');
	num += (G[x][y + 1] == '.');
	num += (G[x + 1][y] == '.');
	num += (G[x + 1][y + 1] == '.');
	if (num != 2)	return true;
	return false;
}
int main() {
	for (int i = 0; i < 4; ++i)	cin >> G[i];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (check(i, j)) {
				cout << "YES\n";
				return 0;
			}

	cout << "NO\n";
	return 0;
}
