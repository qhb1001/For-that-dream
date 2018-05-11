#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int row, col;
string G[105];
void deal() {
	for (int i = row - 2; i >= 0; --i) {
		for (int j = col - 1; j >= 0; --j)
			if (G[i][j] == 'o' && G[i + 1][j] == '.') {
				swap(G[i][j], G[i + 1][j]);
			}
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col;

	for (int i = 0; i < row; ++i) 
		cin >> G[i];

	for (int i = 1; i <= 100; ++i)	deal();

	for (int i = 0; i < row; ++i)	cout << G[i] << endl;
}
