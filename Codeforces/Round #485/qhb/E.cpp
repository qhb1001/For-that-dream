#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 5;
int t[MAX<<1], n;
// void update(int x) {
// 	for (t[x += n]++; x > 1; x >>= 1) {
// 		t[x>>1] = t[x] + t[x^1];
// 	}
// }
// int query(int l, int r) {
// 	l += n; r += n;
// 	int ans = 0;
// 	for (; l < r; l >>= 1, r >>= 1) {
// 		if (l&1)	ans += t[l++];
// 		if (r&1)	ans += t[--r];
// 	}
// 	return ans;
// }
struct Node {
	int l, r, sum;
	struct Node *L, *R;
};
void build(Node *& t, int l, int r) {
	t->l = l; t->r = r; t->sum = 0;
	if (l == r)	return ;
	int mid = (l + r) >> 1;
	t->L = new Node;
	t->R = new Node;
	build(t->L, l, mid);
	build(t->R, mid + 1, r);
}
void update(Node *& t, int now, int l, int r) {
	if (l == r) {
		t->sum++;
		return ;
	}
	int mid = (l + r) >> 1;
	if (now <= mid)	update(t->L, now, l, mid);
	else 	update(t->R, now, mid + 1, r);
	t->sum = t->L->sum + t->R->sum;
}
int query(Node *& t, int l, int r) {
	if (t->l == l && t->r == r) return t->sum;
	int mid = (t->l + t->r) >> 1;
	if (r <= mid)	return query(t->L, l, r);
	else if (l > mid)	return query(t->R, l, r);
	else 	return query(t->L, l, mid) + query(t->R, mid + 1, r);
}
int a[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> a[i];
	long long ans = 0;
	Node * root = new Node;
	build(root, 1, n);
	for (int i = 1; i <= n; ++i) {
		if (a[i] != n)	ans += query(root, a[i] + 1, n);
		// cout << ans << endl;
		update(root, a[i], 1, n);
	}

	// cout << ans << endl;

	if (n&1) {
		if (ans&1)	cout << "Petr";
		else	cout << "Um_nik";
	} else {
		if (ans&1)	cout << "Um_nik";
		else	cout << "Petr";
	}
	return 0;
}
