#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MAX = 1005;
struct Point {
	int x, y;
	void in() {
		scanf("%d%d", &x, &y);
	}
}p[MAX];
int n, L;
int xmult(Point p0, Point p1, Point p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dis(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
int dcmp(double a) {
	if (a > EPS)	return 1;
	else if (a < EPS)	return -1;
	return 0;
}
bool cmpAngle(Point a, Point b) {
	int temp = xmult(p[1], a, b);
	if (temp > 0)	return true;
	else if (temp == 0 && dis(p[1], a) < dis(p[1], b))	return true;
	return false;
}
void in() {
	scanf("%d%d", &n, &L);
	p[1].in();
	int low = 1;
	for (int i = 2; i <= n; ++i) {
		p[i].in();
		if (p[i].y < p[low].y || (p[i].y == p[low].y && p[i].x < p[low].x))
			low = i;
	}
	if (low != 1)	swap(p[1], p[low]);
	sort(p + 2, p + 1 + n, cmpAngle);
}
int s[MAX], top = 0;
double deal() {
	double ans = 0;
	s[0] = 1;
	s[1] = 2;
	top = 2;
	for (int i = 3; i <= n; ++i) {
		while (top >= 2 && xmult(p[s[top - 2]], p[s[top - 1]], p[i]) <= 0)	--top;
		s[top++] = i;
	}

	for (int i = 0; i < top - 1; ++i)
		ans += dis(p[s[i]], p[s[i + 1]]);
	ans += dis(p[1], p[s[top - 1]]);
	ans += PI * 2 * L;
	return ans;
}
int main() {
	in();
	printf("%.0f\n", deal());
}
