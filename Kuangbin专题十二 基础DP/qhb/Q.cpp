#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int row, col;
string G[1005];
struct Point {
	int x, y;
	Point(int a = 0, int b = 0): x(a), y(b){}
}tempPoint;
int deal(int x, int y) {
	Point up(x, y), down(x, y);
	int ans = 1;
	bool flag;
	while(down.x < row && down.y >= 0) {
		flag = 1;
		for(int i = 1; i <= up.y - down.y; ++i)
			if(G[down.x][down.y + i] != G[down.x - i][down.y]) {
				flag = 0;
				break;
			}
		if(flag) {
			ans = max(ans, up.y - down.y + 1);
			down.x++;down.y--;
		} else {
			up.x++;up.y--;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> row && row) {
		col = row;
		for(int i = 0; i < row; ++i)	cin >> G[i];

		int ans = 1;
		for(int i = 0; i < row - 1; ++i) {
			ans = max(ans, deal(0, i));
			ans = max(ans, deal(i, row - 1));
		}
		ans = max(ans, deal(row - 1, row - 1));
		cout << ans << '\n';
	}
}
