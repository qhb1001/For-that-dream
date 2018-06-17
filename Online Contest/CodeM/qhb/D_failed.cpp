#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-3;
double weight[505], inWeight[505], sumWeight;
int n, m, k, C;
struct Node {
	double score[10], val;
	int isTheOne;//record the idx of missing score
	int idx;//the idx of this people
	bool operator < (const Node b) const {
		return val > b.val;
	}
}a[505];
bool notSure[505];
bool equals(double a, double b) {
	if (abs(a - b) <= EPS)	return true;
	return false;
}
void dealNotSure() {
	int cnt = 1;
	for (int i = 2; i <= n; ++i) {
		if (equals(a[i].val, a[i - 1].val))	++cnt;
		else {
			if (cnt < k)	++cnt;
			else if (cnt == k) {
				double same = a[i].val;
				for (int j = i + 1; j <= n; ++j)	if (equals(same, a[j].val))	notSure[a[j].idx] = 1;
				for (int j = 1; j < i; ++j)	if (equals(same, a[j].val))	notSure[a[j].idx] = 1;
				return ;
			}
		}
	}

}
double Max[505];
void in() {
	double temp, sum;
	for (int i = 1; i <= n; ++i) {
		a[i].idx = i;
		a[i].val = 0;
		for (int j = 1; j <= m; ++j) {
			cin >> a[i].score[j];
			temp = a[i].score[j];
			Max[j] = max(Max[j], temp);
			if (temp == -1)	a[i].isTheOne = j;
			else	a[i].isTheOne = 0;
		}
	}
}

bool toWin[505][2];// '0' for the minimum case '1' for maximum case
void dealMin() {
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= k; ++i)	toWin[a[i].idx][0] = 1;
	//for (int i = 1; i <= n; ++i)	cout << a[i].idx << " ";
	//cout << endl;
	dealNotSure();
}
void dealMax() {
	for (int i = 1; i <= n; ++i) {
		if (a[i].isTheOne) {
			int idx = a[i].isTheOne;

			if (Max[idx] != 0)	a[i].val += (C / Max[idx]) * weight[a[i].isTheOne];
			break;
		}
	}

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= k; ++i)	toWin[a[i].idx][1] = 1;

	dealNotSure();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//deal with input and get array weight
	cin >> n >> m >> k >> C;
	for (int i = 1; i <= m; ++i)	{
		cin >> inWeight[i];
		sumWeight += inWeight[i];
	}
	for (int i = 1; i <= m; ++i) {
		weight[i] = inWeight[i] / sumWeight;
	}

	in();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (Max[j] != 0 && a[i].score[i] != -1)	a[i].val += (a[i].score[j] / Max[j]) * weight[j];
		}
	}

	dealMin();
	dealMax();
	for (int i = 1; i <= n; ++i) {
		if (notSure[i])	cout << 3 << '\n';
		else if (toWin[i][0] && toWin[i][1])	cout << 1 << '\n';
		else	cout << 2 << '\n';
	}
}
