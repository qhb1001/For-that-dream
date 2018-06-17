#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, k;
const int MAX = 1e5 + 5;
int head[MAX], cnt;
struct Node {
	int to, nex;
}e[MAX<<1];
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}
int ans = 0, haveCat[MAX];
void dfs(int now, int fa, int cat) {
	if (haveCat[now])	cat++;
	else 	cat = 0;
	int v;
	bool flag = 0;


	if (cat > k)	return ;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		dfs(v, now, cat);
		flag = 1;
	}
	if (!flag)	++ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)	cin >> haveCat[i];
	int u, v;
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	dfs(1, -1, 0);
	cout << ans << endl;
}
