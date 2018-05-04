#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string ans[105];
int r, n, L, R;
int Left[105];//表示这一行座位还剩余多少个位置
bool in(char c, char a, char b) {
	if (c == a)	return true;
	if (c == b)	return true;
	return false;
}
struct Node {
	bool afterExit;//是否在急救舱旁
	int disExit;//距离急救舱的最短距离
	int row, col;//将来进行输出的位置
	int priority;//表示对应座位的优先级
	bool operator < (const Node &b) const {
		//首先选择在哪一行
		if (afterExit != b.afterExit)	return afterExit > b.afterExit;
		if (row != b.row) {
			if (Left[row] != Left[b.row])	return Left[row] > Left[b.row];
			if (disExit != b.disExit)	return disExit < b.disExit;
			return row < b.row;
		}

		//选择在哪一列
		if (priority == b.priority)	{
			if (L <= R)	return col < b.col;//要让col更小的排在前面
			else	return col > b.col;//要让col更大的排在前面	
		}
		return priority > b.priority;
	}
}a[2005], tempNode;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string in;
	int cnt = 0;
	//freopen("input", "r", stdin);
	cin >> r >> n;
	for (int i = 1; i <= r + 3; ++i) {
		ans[i].resize(11);
		cin >> in;
		if (i == 1 || i == r/2 + 2 || i == r + 3) {
			ans[i] = in;
		} else {
			for (int j = 0; j < 11; ++j) {
				ans[i][j] = in[j];
				if (in[j] == '.')	continue;
				else if (in[j] == '#') {
					if (j < 5)	++L;
					else if (j > 5)	++R;
				} else {
					++cnt;
					Left[i]++;
					//查看第一原则
					if (i == 2 || i == r/2 + 3)	a[cnt].afterExit = 1;
					else	a[cnt].afterExit = 0;
					//第二原则
					a[cnt].disExit = min(abs(1 - i), min(abs(r/2 + 2 - i), abs(r + 3 - i)));
					a[cnt].row = i;
					a[cnt].col = j;
					if (j == 4 || j == 6)	a[cnt].priority = 5;
					else if (j == 2 || j == 8)	a[cnt].priority = 4;
					else if (j == 0 || j == 10)	a[cnt].priority = 3;
					else if (j == 5)	a[cnt].priority = 2;
					else	a[cnt].priority = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		sort(a + 1 + i, a + 1 + cnt);

		ans[a[i + 1].row][a[i + 1].col] = 'a' + i;
		if (a[i + 1].col < 5)	++L;
		else if (a[i + 1].col > 5)	++R;
		Left[a[i + 1].row]--;
	}

	for (int i = 1; i <= r + 3; ++i)
		cout << ans[i] << '\n';
}
