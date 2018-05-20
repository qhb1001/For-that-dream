#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 5e3 + 5;
int End[2][30], Begin[2][30];
string a, b;
int lena, lenb;
void in() {
	cin >> a >> b;
	lena = a.size();
	lenb = b.size();
	memset(Begin, -1, sizeof(Begin));
	memset(End, -1, sizeof(End));
	for (int i = 0; i < lena; ++i) {
		End[0][a[i] - 'A'] = i;
	}
	for (int i = 0; i < lenb; ++i) {
		End[1][b[i] - 'A'] = i;
	}

	for (int i = lena - 1; i >= 0; --i)
		Begin[0][a[i] - 'A'] = i;
	for (int i = lenb - 1; i >= 0; --i)
		Begin[1][b[i] - 'A'] = i;
}

int dp[MAX][MAX], L[MAX][MAX];
int check(int i, int j, int ii, int jj, int color) {
	//使用这个函数来简化状态转移
	//特判，如果这个颜色在两个序列中只有一个
	if (Begin[0][color] == End[0][color] && Begin[1][color] == -1)	return 0;
	if (Begin[1][color] == End[1][color] && Begin[0][color] == -1)	return 0;

	//如果该颜色只在一个序列中出现
	if (Begin[0][color] == -1) {//只在第二个序列中出现
		if (j < Begin[1][color] && jj >= Begin[1][color])	return 1;
		if (j < End[1][color] && jj >= End[1][color])	return -1;
		return 0;
	} else if (Begin[1][color] == -1){
		if (i < Begin[0][color] && ii >= Begin[0][color])	return 1;
		if (i < End[0][color] && ii >= End[0][color])	return -1;
		return 0;
	}
	//判断是否是一种颜色的开始
	if (i < Begin[0][color] && j < Begin[1][color] && (ii >= Begin[0][color] || jj >= Begin[1][color]))	return 1;
	//判断是否是一种颜色的结束
	if(ii >= End[0][color] && jj >= End[1][color] && (i < End[0][color] || j < End[1][color]))	return -1;
	return 0;
}
void Deal() {
	dp[0][0] = L[0][0] = 0;
	//初始化两种情况
	for (int i = 1; i <= lena; ++i) {

	}
}
void deal() {
	//更新初始状态
	dp[0][0] = 0; L[0][0] = 0;
	int now, temp;
	for (int i = 0; i <= lena; ++i) {
		//此处的i表示a串使用了多少个元素，与其下标不同
		for (int j = 0; j <= lenb; ++j) {
			//j的意义同上
			//向下方更新，必定是首次更新
			if (i + 1 <= lena) {//更新a串
				temp = L[i][j] + check(i - 1, j - 1, i, j - 1, a[i] - 'A');
				now = dp[i][j] + temp;
				dp[i + 1][j] = now;
				L[i + 1][j] = temp;
			}

			//向右方更新，第一行必定是首次更新
			//除去第一行，其余都是二次更新
			temp = L[i][j] + check(i - 1, j - 1, i - 1, j, b[j] - 'A');
			now = dp[i][j] + temp;
			if (i == 0) {//直接更新
				dp[i][j + 1] = now;
				L[i][j + 1] = temp;
			} else if (j + 1 <= lenb) {
				if (now < dp[i][j + 1]) {
					dp[i][j + 1] = now;
					L[i][j + 1] = temp;
				} else if (now == dp[i][j + 1] && temp < L[i][j + 1]) L[i][j + 1] = temp;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		in();
		deal();
		cout << dp[lena][lenb] << '\n';

		//cout << check(-1, -1, -1, 0, 'Y' - 'A') << endl;
		// int tempa, tempb;
		// while (true) {
		// 	cin >> tempa >> tempb;
		// 	cout << "dp : " << dp[tempa][tempb] << " L : " << L[tempa][tempb] << endl;
		// }
	}
}
