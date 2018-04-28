#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string a;
const int MAX = 1e4;
char op[MAX];
int cnt;
struct Node {
	char c;
	struct Node* L, *R;
};

void build2(Node*& t, int l, int r) {
	int c1 = -1, c2 = -1, p = 0;

	if (r - l == 1) {
		t->L = t->R = NULL;
		t->c = a[l];
		return ;
	}
	for (int i = l; i < r; ++i) {
		if (a[i] == '(') ++p;
		else if (a[i] == ')')	--p;
		else if (a[i] == '+' || a[i] == '-') {
			if (!p)	c1 = i;
		} else if (a[i] == '*' || a[i] == '/') {
			if (!p)	c2 = i;
		}
	}

	if (c1 < 0)	c1 = c2;
	if (c1 < 0)	{
		build2(t, l + 1, r - 1);
		return ;
	}

	t->L = (Node*)malloc(sizeof(Node));
	t->R = (Node*)malloc(sizeof(Node));
	build2(t->L, l, c1);
	build2(t->R, c1 + 1, r);
	t->c = a[c1];
	return ;
}

void post(Node*& t) {
	if (t->L == NULL && t->R == NULL) {
		cout << t->c;
		return ;
	}

	post(t->L);
	post(t->R);
	cout << t->c;
}
int l[MAX], r[MAX];
int build(int x, int y) {
	int i, c1 = -1, c2 = -1, p = 0, u;
	if (y - x == 1)	{
		u = ++cnt;
		l[u] = r[u] = 0;
		op[u] = a[x];
		return u;
	}

	for (i = x; i < y; ++i) {
		switch (a[i]) {
			case '(': ++p; break;
			case ')': --p; break;
			case '+': case '-': if (!p)	c1 = i; break;
			case '*': case '/': if (!p)	c2 = i; break;
		}
	}

	if (c1 < 0)	c1 = c2;
	if (c1 < 0)	return build(x + 1, y - 1);
	u = ++cnt;
	l[u] = build(x, c1);
	r[u] = build(c1 + 1, y);
	op[u] = a[c1];
	return u;
}

void postTraverse(int now) {
	if (l[now] == 0 && r[now] == 0)	{
		cout << op[now];
		return ;
	}

	postTraverse(l[now]);
	postTraverse(r[now]);
	cout << op[now];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a;
	build(0, a.size());

	postTraverse(1);
	cout << endl;

	Node* t = (Node*)malloc(sizeof(Node));
	build2(t, 0, a.size());
	post(t);
}
