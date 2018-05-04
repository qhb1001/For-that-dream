#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
struct Node {
	long val, lazy;
	int l, r;
	struct Node* L, *R;
};
const int MAX = 1e5 + 5;
long a[MAX];
int n;
long max(long a, long b) {
	if (a > b)	return a;
	return b;
}
void build(Node*& t, int l, int r) {
	t->l = l;
	t->r = r;
	t->lazy = 0;
	if (l == r) {
		t->val = a[l];
		return ;
	}

	t->L = (Node*)malloc(sizeof(Node));
	t->R = (Node*)malloc(sizeof(Node));
	int mid = (l + r) >> 1;
	build(t->L, l, mid);
	build(t->R, mid + 1, r);

	t->val = max(t->L->val, t->R->val);
}

void update(Node*& t, int l, int r, long add) {
	if(l == t->l && r == t->r) {
		t->val += add;
		t->lazy += add;
		return ;
	}

	int mid = (t->r + t->l) >> 1;
	if (r <= mid)	update(t->L, l, r, add);
	else if (l > mid)	update(t->R, l, r, add);
	else update(t->L, l, mid, add), update(t->R, mid + 1, r, add);

	//下面这一句不知道有没有加的必要
	//唔，应该是有的
	t->val = max(t->L->val, t->R->val) + t->lazy;
}

void push(Node*& t) {
	if (t->l == t->r)	return ;
	t->L->val += t->lazy;
	t->L->lazy += t->lazy;
	t->R->val += t->lazy;
	t->R->lazy += t->lazy;
	t->lazy = 0;
}

long query(Node*& t, int l, int r) {
	push(t);
	if (t->l == l && t->r == r) {
		return t->val;
	}

	int mid = (t->l + t->r) >> 1;
	if (r <= mid)	return query(t->L, l, r);
	else if (l > mid)	return query(t->R, l, r);
	else return max(query(t->L, l, mid), query(t->R, mid + 1, r));
}
Node* t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	t = (Node*)malloc(sizeof(Node));
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	build(t, 1, n);

	int type, l, r;
	long add;
	cin >> n;
	while (n--) {
		cin >> type >> l >> r;
		if (type == 2) cout << query(t, l, r) << '\n';
		else {
			cin >> add;
			update(t, l, r, add);
		}
	}
}
