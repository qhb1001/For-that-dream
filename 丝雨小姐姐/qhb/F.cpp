#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int MAX = 1005;
const double EPS = 1e-7;
int dcmp(double a) {
	if (a > EPS)	return 1;
	if (a < EPS)	return -1;
	return 0;
}
struct Point {
	double x, y;
	void in() {
		cin >> x >> y;
	}
}p[MAX];
int n;
double d;
bool work[MAX];
double dis(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
int fa[MAX], cnt[MAX];
void init() {
	for (int i = 1; i <= n; ++i)	
		fa[i] = i, cnt[i] = 1;
}
int find(int u) {
	return fa[u] == u? u : fa[u] = find(fa[u]);
}
void unit(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)	return ;
	if (cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	init();
	for (int i = 1; i <= n; ++i)	p[i].in();
	string type;
	int u, v;
	while (cin >> type) {
		if (type[0] == 'O') {
			cin >> u;
			if (work[u])	continue;
			work[u] = 1;
			for (int i = 1; i <= n; ++i) {
				if (work[i] && dcmp(dis(p[i], p[u]) - d) <= 0) {
					unit(u, i);
				}
			}
		} else {
			cin >> u >> v;
			if (find(u) == find(v)) cout << "SUCCESS\n";
			else	cout << "FAIL\n";
		}
	}
}
