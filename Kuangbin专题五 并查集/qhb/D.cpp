#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 2e5 + 5;
int fa[MAX], val[MAX];
int find(int x) {
	if(fa[x] == x)	return x;
	int t = fa[x], tt = find(fa[x]);
	val[x] += val[fa[x]];
	return fa[x] = tt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while(cin >> n >> m) {
		for(int i = 0; i <= n; ++i)	fa[i] = i, val[i] = 0;
		int l, r, value, ans = 0;
		for(int i = 1; i <= m; ++i) {
			cin >> l >> r >> value;
			--l;
			int u = find(l), v = find(r);
			if(find(l) != find(r)) {
				fa[v] = u;
				val[v] = value + val[l] - val[r];
			} else {
				if(value != val[r] - val[l])	++ans;
			}
		}
		cout << ans << '\n';
	}

}
