#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
	double x, y;
	void in() {
		scanf("%lf%lf", &x, &y);
	}
	bool operator < (const Node b) const {
		return x < b.x;
	}
}p[MAX];
int n;
double ans;
const double EPS = 1e-6;
double abs(double a) {
	if (a > EPS)	return a;
	else	return -a;
}
void deal() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)	p[i].in();
	sort(p + 1, p + 1 + n);

	ans = 0;
	for (int i = 1;  i< n; ++i) {
		if (p[i].x == p[i + 1].x)	ans = -1;
		else {
			ans = max(ans, abs((p[i].y - p[i + 1].y) / (p[i].x - p[i + 1].x)));
		}

		if (ans == -1)	return ;
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		deal();
		printf("%.6lf\n", ans);
	}



}
