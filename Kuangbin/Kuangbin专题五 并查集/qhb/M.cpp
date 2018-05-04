#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
int fa[MAX], cnt[MAX];
void init() {
	for(int i = 0; i < MAX; ++i)
		fa[i] = i, cnt[i] = 1;
}
int find(int x) {
	return fa[x] == x? x : fa[x] = find(fa[x]);
}
bool unit(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v)	return false;
	if(cnt[v] > cnt[u])	swap(u, v);
	cnt[u] += cnt[v];
	fa[v] = u;
	return true;
}
bool vis[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b, cnt;
	while(cin >> a >> b && a != -1) {
		if(a == b && a == 0) {
			cout << "Yes\n";
			continue;
		}
		cnt = 1;
		init();
		memset(vis, 0, sizeof(vis));
		unit(a, b);
		int temp = a;
		bool flag = 1;
		while(cin >> a >> b && a) {
			vis[a] = vis[b] = 1;
			if(!unit(a, b)) flag = 0;
		}

		for(int i = 1; i < MAX; ++i)
			if(vis[i] && find(temp) != find(i))
				flag = 0;
		if(flag)	cout << "Yes\n";
		else	cout << "No\n";
	}
}
