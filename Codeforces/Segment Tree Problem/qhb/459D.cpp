#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAX = 2e6 + 5;
const int N = 1e6;
int t[MAX], n;
void build() {}//走一走程序。。

void update(int x, int change) {//把x位置的值修改 change 大小
	for (t[x += N] += change; x > 1; x >>= 1) {
		t[x>>1] = t[x] + t[x^1];
	}
}
int query(int l, int r) {//询问区间[l, r)的和
	int ans = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if(l&1)	ans += t[l++];
		if(r&1)	ans += t[--r];
	}
	return ans;
}
map<int, int>mp;
int a[N + 5], b[N + 5], c[N + 5], vis[N + 5];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	int cnt = 1, temp;
	//使用a数组对输入离散化
	for (int i = 1; i <= n; ++i) {
		cin >> temp;
		if(mp.count(temp) == 0)	mp[temp] = cnt++;
		a[i] = mp[temp];
	}

	//b数组为从左到右，c数组为从右到左
	for (int i = 1; i <= n; ++i)
		b[i] = ++vis[a[i]];
	memset(vis, 0, sizeof(vis));
	for (int j = n; j >= 1; --j)
		c[j] = ++vis[a[j]];

	long long ans = 0;
	for (int i = n; i >= 1; --i) {
		ans += query(0, b[i]);
		update(c[i], 1);
	}

	cout << ans << '\n';
}
