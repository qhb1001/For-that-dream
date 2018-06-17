#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 505;
int state[MAX][MAX];// the first var means the idx of element
// the second var means the val of -1
struct Node {
	double score[10], val;
	int idx, isTheOne;
	bool operator < (const Node b) const {
		return val > b.val;
	}
}a[MAX];
int theOne, theCol, n, m, k, C;
double weight[MAX], Max[MAX];
void in() {
	cin >> n >> m >> k >> C;
	double temp[MAX], sum = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> temp[i];
		sum += temp[i];
	}
	for (int i = 1; i <= m; ++i) {
		weight[i] = temp[i] / sum;
	}

	for (int i = 1; i <= n; ++i) {
		a[i].val = 0;
		a[i].idx = i;
		for (int j = 1; j <= m; ++j) {
			cin >> a[i].score[j];
			Max[j] = max(Max[j], a[i].score[j]);
			if (a[i].score[j] == -1) {
				a[i].isTheOne = 1;
				theOne = i;
				theCol = j;
			} else 	a[i].isTheOne = 0;
		}
	}
}

void getThe() {
	for (int i = 1; i <= n; ++i) {
		if (a[i].isTheOne)	{
			theOne = i;
			return ;
		}
	}
}
void getVal() {
	for (int i = 1; i <= n; ++i) {
		a[i].val = 0;
		for (int j = 1; j <= m; ++j) {
			if (Max[j] != 0) {
				a[i].val += (a[i].score[j] / Max[j]) * weight[j];
			}
		}
	}
}

void out() {
	for (int i = 1; i <= n; ++i)	cout << a[i].idx << " ";
	cout << endl;
	for (int i = 1; i <= n; ++i)	cout << a[i].val << " ";
	cout << endl;
}
//这里也许需要重载浮点数的比较，不过先放一放
void getState(int now) {// 'now' means the val of -1
	sort(a + 1, a + 1 + n);
	//在读入之后就对 k = n 的情况特判，所以此处不会出现 k = n
	//out();
	if (a[k].val == a[k + 1].val) {
		int l = k, r = k;
		while (l >= 1 && a[l].val == a[k].val)	--l;
		while (r <= n && a[r].val == a[k].val)	++r;
		for (int i = 1; i <= n; ++i) {
			if (i <= l)	state[a[i].idx][now] = 1;
			else if (i >= r)	state[a[i].idx][now] = 0;
			else	state[a[i].idx][now] = -1;//not sure
		}
	} else {
		for (int i = 1; i <= k; ++i)	state[a[i].idx][now] = 1;//to win
		for (int i = k + 1; i <= n; ++i)	state[a[i].idx][now] = 0;// to lose
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	in();
	if (n == k) {
		for (int i = 1; i <= n; ++i)	cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i <= C; ++i) {
		getThe();
		a[theOne].score[theCol] = i;
		Max[theCol] = max(Max[theCol], i * 1.0);
		getVal();
		getState(i);
	}

	for (int i = 1; i <= n; ++i) {
		//flag1 for all 1   flag0 for all 0
		bool flag1 = 1, flag0 = 1;
		for (int j = 0; j <= C; ++j) {
			if (state[i][j] != 1)	flag1 = 0;
			if (state[i][j] != 0)	flag0 = 0;
		}

		if (flag1)	cout << 1 << '\n';
		else if (flag0)	cout << 2 << '\n';
		else	cout << 3 << '\n';
	}
}
