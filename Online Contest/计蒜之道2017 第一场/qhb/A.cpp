#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10][10], row, col;
struct Node {
	int x, y;
	Node(int a = 0, int b = 0): x(a), y(b){}
}node;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tempa, tempb;
	cin >> tempa >> tempb;
	while (tempa--) {
		cin >> node.x >> node.y;
		a[node.x + 3][node.y + 3] = 1;
	}

	int ans = 0;
	for (int i = 0; i < 7; ++i){//首先计算横向
		int cnt = 0;
		if (i == 3)	continue;
		for (int j = 0; j < 7; ++j)	cnt += a[i][j];
		if (cnt == 3)	++ans;
		
		cnt = 0;
		for (int j = 0; j < 7; ++j)	cnt += a[j][i];
		if (cnt == 3)	++ans;
	}

	if (a[3][0] && a[3][1] && a[3][2])	++ans;
	if (a[3][4] && a[3][5] && a[3][6])	++ans;
	if (a[0][3] && a[1][3] && a[2][3])	++ans;
	if (a[4][3] && a[5][3] && a[6][3])	++ans;

	cout << ans << endl;

}
