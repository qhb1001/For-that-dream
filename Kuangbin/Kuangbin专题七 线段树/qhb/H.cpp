#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 2e5 + 5;
struct Node {
	bool type;//if all values in this segment are '1'
	long long val;
}t[MAX];
int n, m;
void build() {
	for(int i = n - 1; i > 0; --i) {
		if(t[i<<1].type && t[i<<1|1].type)	t[i].type = 1;
		else	t[i].type = 0;
		t[i].val = t[i<<1].val + t[i<<1|1].val;
	}
}
void up(int x) {
	while(x > 1) {
		t[x>>1].val = t[x].val + t[x^1].val;
		x >>= 1;
	}
}
long long deal(int x) {
	if(t[x].type == 1)	return t[x].val;
	if(x >= n) {
//		cout << x << " " << t[x].val << " -> " << (int)sqrt(t[x].val) << endl;
		t[x].val = sqrt(t[x].val);
//		cout << "now : " << t[x].val << endl;
		if(t[x].val <= 1)	t[x].type = 1;
		up(x);
		return t[x].val;
	}
	if(t[x<<1].type != 1)	deal(x<<1);
	if(t[x<<1|1].type != 1)	deal(x<<1|1);

	t[x].val = t[x<<1].val + t[x<<1|1].val;
	if(t[x<<1].type && t[x<<1|1].type)	t[x].type = 1;
	up(x);
	return t[x].val;
}
void update(int l, int r) {
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1) deal(l++);
		if(r&1)	deal(--r);
	}
}
long long query(int l, int r) {
	long long ans = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)	{
			ans += t[l++].val;
		}
		if(r&1)	{
			ans += t[--r].val;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 1;
	// freopen("input", "r", stdin);
	// freopen("output.a", "w", stdout);
	while(cin >> n) {
		cout << "Case #" << cnt++ << ":\n";
		for(int i = 0; i < n; ++i) {
			cin >> t[i + n].val;
			if(t[i + n].val <= 1)	t[i + n].type = 1;
			else	t[i + n].type = 0;
		}
		build();

		cin >> m;
		int type, l, r;
		while(m--) {
			cin >> type >> l >> r;
			if(l > r)	swap(l, r);
			if(type == 0)	update(l - 1, r);
			else	cout << query(l - 1, r) << '\n';
		}
		cout << '\n';
	}
}
