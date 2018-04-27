#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 105;
int fa[MAX], cnt[MAX];
int find(int x) {
	return fa[x] == x? x : fa[x] = find(fa[x]);
}
void unit(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v)	return ;
	if (cnt[u] < cnt[v])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
}
struct Node {
	int x, y;
	Node(int a = 0, int b = 0): x(a), y(b) {}
	void in() {
		cin >> x >> y;
	}
}node[105];
bool check(Node& a, Node& b) {
	if(a.y == b.y)	return true;
	if(a.x == b.x)	return true;
	return false;
}

void init() {
	for (int i = 1; i <= 100; ++i)
		fa[i] = i, cnt[i] = 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	init();
	for (int i = 1; i <= n; ++i)	node[i].in();

	for (int i = 1; i < n; ++i) 
		for(int j = i + 1; j <= n; ++j)
			if(check(node[i], node[j]))
				unit(i, j);

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if(fa[i] == i)	++ans;

	cout << ans - 1 << endl;
}
