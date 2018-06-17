#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAX = 9e4 + 5;
const int INF = 1<<30;
struct Node {
	int l, r, val, tag;
}t[MAX<<2];
int Begin, End;
void maintain(int id) {
	t[id].val = min(t[id<<1].val, t[id<<1|1].val);
}
void build(int id, int l, int r) {
	t[id].l = l;
	t[id].r = r;
	t[id].tag = INF;
	if (l == r) {
		t[id].val = (l <= Begin? 0: INF);
	} else {
		int mid = (l + r) >> 1;
		build(id<<1, l, mid);
		build(id<<1|1, mid + 1, r);
		maintain(id);
	}
}
void down(int id) {
	if (t[id].l != t[id].r) {
		t[id<<1].val = min(t[id<<1].val, t[id].tag);
		t[id<<1].tag = min(t[id<<1].tag, t[id].tag);
		t[id<<1|1].val = min(t[id<<1|1].val, t[id].tag);
		t[id<<1|1].tag = min(t[id<<1|1].tag, t[id].tag);
		t[id].tag = INF;
	}
}
void update(int id, int l, int r, int val) {
	down(id);
	if (l <= t[id].l && t[id].r <= r) {
		t[id].tag = min(t[id].tag, val);
		t[id].val = min(t[id].val, val);
	} else {
		int mid = (t[id].l + t[id].r) >> 1;
		if (l <= mid)	update(id<<1, l, r, val);
		if (r > mid)	update(id<<1|1, l, r, val);
		maintain(id);
	}
}
int query(int id, int l, int r) {
	down(id);
	if (l <= t[id].l && t[id].r <= r) {
		return t[id].val;
	} else {
		int ans = INF, mid = (t[id].l + t[id].r) >> 1;
		if (l <= mid)	ans = min(ans, query(id<<1, l, r));
		if (r > mid)	ans = min(ans, query(id<<1|1, l, r));
		return ans;
	}
}
struct Cow {
	int s, t, cost;
	bool operator < (const Cow b) const {
		return s < b.s;
	}
}cow[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, delta = 0;
	cin >> n >> Begin >> End;
	build(1, 0, MAX - 1);
	if (Begin == 0)	delta = 1;
	Begin += delta;
	End += delta;
	for (int i = 1; i <= n; ++i) {
		cin >> cow[i].s >> cow[i].t >> cow[i].cost;
		cow[i].s += delta;
		cow[i].t += delta;
	}
	sort(cow + 1,  cow + 1 + n);
	int temp;
	for (int i = 1; i <= n; ++i) {
		temp = query(1, max(cow[i].s - 1, 0), cow[i].t);
		if (temp == INF)	continue;
		temp += cow[i].cost;
		update(1, cow[i].s, cow[i].t, temp);
	}

	int ans = query(1, End, End);
	if (ans == INF)	cout << -1 << '\n';
	else	cout << ans << '\n';
	return 0;
}
