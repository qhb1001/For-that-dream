#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int MAX = 1005;
int fa[MAX], cnt[MAX];
int find(int x) {
	return fa[x] == x? x : fa[x] = find(fa[x]);
}
bool ok[MAX];
vector<pair<double, double> >q;
void unit(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v)	return ;
	if(cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
}

void init() {
	for(int i = 0 ;i < 1000; ++i)
		fa[i] = i, cnt[i] = 1;
}
int main() {
	int n;
	double tempa, tempb, m, dx, dy;
	scanf("%d%lf", &n, &m);
	m *= m;
	for(int i = 1; i <= n; ++i) {
		scanf("%lf%lf", &tempa, &tempb);
		q.push_back(make_pair(tempa, tempb));
	}

	char op[2];
	int a, b;
	init();
	while(scanf("%s", op) != EOF) {
		if(op[0] == 'O')	scanf("%d", &a);
		else	scanf("%d%d", &a, &b);

		--a;--b;
		if(op[0] == 'O') {
			ok[a] = 1;
			for(int i = 0; i < n; ++i)
				if(i != a && ok[i]) {
					dx = q[i].first - q[a].first;
					dy = q[i].second - q[a].second;
					if(dx * dx + dy * dy <= m)	unit(i, a);
				}
		} else {
			if(find(a) != find(b)) printf("FAIL\n");
			else	printf("SUCCESS\n");
		}
	}
}
