#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node {
	double score[10], val;
	int isTheOne, idx;
	bool operator < (const Node b) const {
		return val > b.val;
	}
}a[505];
int n, m, k, C;
double weight[505], Max[505];
const double EPS = 1e-5;
bool equals(double a_, double b) {
	if (abs(a_ - b) <= EPS)	return true;
	return false;
}
int state[505][2];// '1' for to win  '0' for to lose  '-1' for not sure
void getVal() {
	for (int i = 1; i <= n; ++i) {
		a[i].val = 0;
		for (int j = 1; j <= m; ++j) {
			if (Max[j] != 0 && a[i].score[j] != -1)
				a[i].val += (a[i].score[j] / Max[j]) * weight[j];
		}
	}
}
void in() {
	cin >> n >> m >> k >> C;
	double temp[505], sum = 0;// record the weight of each contest
	memset(state, -1, sizeof(state));
	for (int i = 1; i <= m; ++i)	{
		cin >> temp[i];
		sum += temp[i];
	}
	for (int i = 1; i <= m; ++i)	weight[i] = temp[i] / sum;

	//input Node
	for (int i = 1; i <= n; ++i) {
		a[i].isTheOne = 0;
		a[i].idx = i;
		for (int j = 1; j <= m; ++j) {
			cin >> a[i].score[j];
			Max[j] = max(Max[j], a[i].score[j]);
			if (a[i].score[j] == -1)	a[i].isTheOne = j;
		}
	}

}

void out() {
	for (int i = 1; i <= n; ++i)	cout << a[i].idx << " ";
	cout << endl;
	for (int i = 1; i <= n; ++i)	cout << a[i].val << " ";
	cout << endl;
}

void dealMin() {
	getVal();
	sort(a + 1, a + 1 + n);
	//out();
	int boundOfRight = k, boundOfLeft = k;
	double same = a[k].val;
	while (boundOfLeft <= n && equals(same, a[boundOfLeft].val))	++boundOfLeft;
	while (boundOfRight >= 1 && equals(same, a[boundOfRight].val))	--boundOfRight;
	if (boundOfLeft == k + 1)	boundOfRight = k;
	for (int i = 1; i <= boundOfRight; ++i)	state[a[i].idx][0] = 1;
	for (int i = boundOfLeft; i <= n; ++i)	state[a[i].idx][0] = 0;
}

void dealMax() {
	for (int i = 1; i <= n; ++i) {
		if (a[i].isTheOne) {
			int idx = a[i].isTheOne;
			Max[idx] = max(Max[idx], (double)C);
			a[i].score[idx] = C;
		}
	}
	getVal();
	sort(a + 1, a + 1 + n);
	//out();
	int boundOfRight = k, boundOfLeft = k;
	double same = a[k].val;
	while (boundOfLeft <= n && same == a[boundOfLeft].val)	++boundOfLeft;
	while (boundOfRight >= 1 && same == a[boundOfRight].val)	--boundOfRight;
	if (boundOfLeft == k + 1)	boundOfRight = k;
	for (int i = 1; i <= boundOfRight; ++i)	state[a[i].idx][1] = 1;
	for (int i = boundOfLeft; i <= n; ++i)	state[a[i].idx][1] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	in();
	if (k == n) {
		for (int i =1 ; i <= n; ++i)	cout << 1 << endl;
		return 0;
	}
	dealMin();
	dealMax();
	for (int i = 1; i <= n; ++i) {
		if (state[i][0] == 1 && state[i][1] == 1)	cout << 1 << '\n';
		else if (state[i][0] == 0 && state[i][1] == 0)	cout << 2 << '\n';
		else	cout << 3 << '\n';
	}
	return 0;
}
