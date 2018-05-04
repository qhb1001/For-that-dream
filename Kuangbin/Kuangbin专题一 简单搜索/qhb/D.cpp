#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;
int row, col;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
bool now[20][20], a[20][20], op[20][20];
void flip(int r, int c) {
	int x, y;
	now[r][c] = !now[r][c];
	for(int i = 0; i < 4; ++i) {
		x = X[i] + r;
		y = Y[i] + c;
		if(x < 0 || y < 0 || x >= row || y >= col)	continue;
		now[x][y] = !now[x][y];
	}
}

bool check() {
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			if(now[i][j])	return false;
	return true;
}

vector<string>q;
void insert() {
	string ans = "";
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			ans += op[i][j] + '0';
	q.push_back(ans);
}
bool deal() {
	for(int i = 0; i <= (1<<(col + 1)) - 1; ++i) {
		memcpy(now, a, sizeof(now));
		memset(op, 0, sizeof(op));
		bitset<20>bit(i);
		for(int j = 0; j < col; ++j) {
			if(bit[j])	{
				flip(0, j);
				op[0][j] = 1;
			}
		}

		for(int j = 1; j < row; ++j) {
			for(int k = 0; k < col; ++k) {
				if(now[j - 1][k]) {
					flip(j, k);
					op[j][k] = 1;
				}
			}
		}

		if(check()) return true;

	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> row >> col;
	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			cin >> a[i][j];

	deal();

	if(!deal()) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for(int i = 0; i < row; ++i) {
		for(int j = 0; j < col - 1; ++j) {
			cout << op[i][j] << ' ';
		}
		cout << op[i][col - 1] << '\n';
	}
	return 0;
}
