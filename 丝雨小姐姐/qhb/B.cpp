#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;
const double PI = 3.1415926535;
struct Node {
	double x, h, Left, Right;
	int id;
}in[MAX<<1];
int n, m;
double xmult(Node a, Node b, Node c) {
	return (a.x - c.x) * (b.h - c.h) - (b.x - c.x) * (a.h - c.h);
}
int dcmp(double a) {
	if (a > EPS)	return 1;
	else if (a < EPS)	return -1;
	return 0;
}

void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &in[i].x, &in[i].h);
		in[i].id = -1;
	}
	scanf("%d", &m);
	for (int i = n + 1; i <= n + m; ++i) {
		scanf("%lf", &in[i].x);
		in[i].h = 0;
		in[i].id = i - n;
	}
	sort(in + 1, in + 1 + m + n, [](Node a, Node b) {
				return a.x < b.x;
			});
}
int top, s[MAX<<1];
double ans[MAX];
void deal() {
	top = 0;
	for (int i = 1; i <= n + m; ++i) {
		while (top >= 2 && dcmp(xmult(in[s[top - 1]], in[s[top - 2]], in[i])) <= 0)	--top;
		if (top)	in[i].Left = atan(in[s[top - 1]].h / (in[i].x - in[s[top - 1]].x));
		s[top++] = i;
	}

	top = 0;
	for (int i = n + m; i >= 1; --i) {
		while (top >= 2 && dcmp(xmult(in[s[top - 1]], in[s[top - 2]], in[i])) >= 0)	--top;
		if (top)	in[i].Right = atan(in[s[top - 1]].h / (in[s[top - 1]].x - in[i].x));
		s[top++] = i;
	}

	for (int i = 1; i <= n + m; ++i) {
		if (in[i].id != -1) {
			ans[in[i].id] = 180 * (PI - in[i].Right - in[i].Left) / PI;
		}
	}
}
int main() {
	int T, kase = 1;
	scanf("%d", &T);
	while (T--) {
		input();
		deal();
		printf("Case #%d:\n", kase++);
		for (int i = 1; i <= m; ++i) 
			printf("%.8lf\n", ans[i]);
	}
}
