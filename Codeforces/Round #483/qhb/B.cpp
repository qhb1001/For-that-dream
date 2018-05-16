#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int row, col;
string G[105];
int X[10] = {0, 0, -1, -1, -1, 1, 1, 1};
int Y[10] = {1, -1, 1, -1, 0, 1, -1, 0};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col;
	for (int i = 0; i < row; ++i)	cin >> G[i];
	//cout << (int)'0' << " " << (int)'.' << endl;

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {

			if (G[i][j] == '*') {
				int x = i, y = j;
				for (int k = 0; k < 8; ++k) {
					int nowx = x + X[k];
					int nowy = y + Y[k];
					if (nowx >= 0 && nowy >= 0 && nowx < row && nowy < col) {
						if (G[nowx][nowy] != '.' && G[nowx][nowy] != '*')	G[nowx][nowy]--;
						if (G[nowx][nowy] == '0' - 1)	{
							cout << "NO\n";
							return 0;
						}
					}
				}
			} else if (G[i][j] == '.') {
				int x = i, y = j;
				for (int k = 0; k < 8; ++k) {
					int nowx = x + X[k];
					int nowy = y + Y[k];

					if (nowx >= 0 && nowy >= 0 && nowx < row && nowy < col)	{
						if (G[nowx][nowy] == '*')	{
							cout << "NO\n";
							return 0;
						}
					}
				}
			}
		}

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			if (G[i][j] != '*' && G[i][j] != '.') {
				if (G[i][j] != '0') {
					cout << "NO\n";
					return 0;
				}
			}
		}

	//cout << G[1] << endl;
	cout << "YES\n";
	return 0;
}
