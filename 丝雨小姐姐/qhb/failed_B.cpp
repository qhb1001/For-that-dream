#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
const double PI = 3.1415926535;
struct Node {
	double x, h;
	bool operator < (const Node b) const {
		return x < b.x;
	}
}building[MAX];
struct Query{
	double x, idx;
	double Left, Right;
}query[MAX];
int T, n, q;
void dealLeft() {
	double Max = 0, now;
	int l = 1, r = 1;
	while (r != q + 1) {
		if (building[l].x < query[r].x) {
			now = 1.0 * building[l].h / (query[r].x - building[l].x);
			if (Max < now)	Max = now;
			++l;
		} else {//绝对是建筑物在人右边
			query[r].Left = atan(Max);
			++r;
		}
	}
}
void dealRight() {
	double Max = 0, now;
	int l = n, r = q;
	while (r != 0) {
		if (building[l].x > query[r].x) {
			now = 1.0 * building[l].h / (building[l].x - query[r].x);
			if (Max < now)	Max = now;
			--l;
		} else {
			query[r].Right = atan(Max);
			--r;
		}
	}
}
int main() {
	scanf("%d", &T);
	int kase = 1;
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)	scanf("%lf%lf", &building[i].x, &building[i].h);
		sort(building + 1, building + 1 + n);
		scanf("%d", &q);
		for (int i = 1; i <= q; ++i) {
			scanf("%lf", &query[i].x);
			query[i].idx = i;
		}
		sort(query + 1, query + 1 + q, [](Query a, Query b) {
					return a.x < b.x;
				});
		dealLeft();dealRight();
		sort(query + 1, query + 1 + q, [](Query a, Query b) {
					return a.idx < b.idx;
				});
		printf("Case #%d:\n", kase++);
		for (int i = 1; i <= q; ++i) {
			printf("%.8lf\n", 180 * (PI - query[i].Left - query[i].Right) / PI);
		}
	}
}
