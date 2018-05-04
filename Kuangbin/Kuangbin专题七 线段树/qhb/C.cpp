#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 2e5 + 5;
typedef long long ll;
int n;
struct Node {
	ll lazy, val;
}t[MAX];
void build() {
	for(int i = n - 1; i > 0; --i) {
		t[i].lazy = 0;
		t[i].val = t[i<<1].val + t[i<<1|1].val;
	}
}
void up(int x) {
	while(x > 1) {
		t[x>>1].val = t[x].val + t[x^1].val;
		x >>= 1;
	}
}
ll deal(int x) {
	if(t[x].lazy == 0)	return t[x].val;
	if(x >= n) {
		t[x].val += t[x].lazy;
		t[x].lazy = 0;
		up(x);
		return t[x].val;
	}

	t[x<<1].lazy += t[x].lazy;
	t[x<<1|1].lazy += t[x].lazy;
	t[x].lazy = 0;
	t[x].val = deal(x<<1) + deal(x<<1|1);
	up(x);
	return t[x].val;
}
void update(int l, int r, ll val) {
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)	t[l].lazy = val, deal(l++);
		if(r&1)	t[r - 1].lazy = val, deal(--r);
	}
}
ll query(int l, int r) {
	ll ans = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)	ans += t[l++].val;
		if(r&1)	ans += t[--r].val;
	}
	return ans;
}
int main() {
	int m, l, r;
	ll val;
	char s[2];
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i)	{
		scanf("%lld", &t[i + n].val);
		t[i + n].lazy = 0;
	}
	build();
	while(m--) {
		scanf("%s", s);
		if(s[0] == 'Q') {
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(l - 1, r));
		} else {
			scanf("%d%d%lld", &l, &r, &val);
			update(l - 1, r, val);
		}
	}

}
