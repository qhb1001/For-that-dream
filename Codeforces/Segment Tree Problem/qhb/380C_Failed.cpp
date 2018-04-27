/*
 * 由于递归版线段树的一个重要优化是当区间完全匹配时直接进行输出，而如果仍然要继续地递归下去，复杂度
 * 就与暴力无异了
 * 而由于本题在对于每组询问时相当于是一种在线算法，所以就很麻烦
 * 所以我决定再搞一颗线段树，当区间完全匹配的时候使用
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
const int MAX = 1e6 + 5;
struct Node {
	int l, r, Left, Right, ans;
	struct Node* L, * R;
};
char a[MAX];
void build(Node*& t, int l, int r) {
	t->l = l;
	t->r = r;
	if(l == r)	{
		t->Left = t->Right = t->ans = 0;
		if (a[t->l] == '(')	t->Left = 1;
		else	t->Right = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	t->L = (Node*)malloc(sizeof(Node));
	t->R = (Node*)malloc(sizeof(Node));
	build(t->L, l, mid);
	build(t->R, mid + 1, r);

	int ans = min(t->L->Left, t->R->Right);
	t->ans = t->L->ans + t->R->ans + ans;
	t->Left = t->L->Left + t->R->Left - ans;
	t->Right = t->L->Right + t->R->Right - ans;
}

Node* temp;
int query(Node* t, Node* tt, int l, int r) {
	if(l == t->l && r == t->r) {
		t->Left = tt->Left;
		t->Right = tt->Right;

		return t->ans = tt->ans;
	}

	int mid = (t->l + t->r) >> 1;

	if (r <= mid) {
		t->ans = query(t->L, tt->L, l, r);
		t->Left = t->L->Left;
		t->Right = t->L->Right;
		return t->ans;
	}
	else if (l > mid)	{
		t->ans = query(t->R, tt->R, l, r);
		t->Left = t->R->Left;
		t->Right = t->R->Right;
		return t->ans;
	}
	else {
		//只有在这个时候才需要进行合并操作
		t->ans = query(t->L, tt->L, l, mid) + query(t->R, tt->R, mid + 1, r);
		int ans = min(t->L->Left, t->R->Right);

		t->ans += ans;
		t->Left = t->L->Left + t->R->Left - ans;
		t->Right = t->L->Right + t->R->Right - ans;
//		cout << l << " " << r << " " << t->ans << endl;
//		cout << t->Left << " " << t->Right << endl;
	}
	return t->ans;
}
Node* t;
int main() {
	scanf("%s", a);
	int len = strlen(a);

	t = (Node*)malloc(sizeof(Node));
	temp = (Node*)malloc(sizeof(Node));
	build(t, 0, len - 1);
	build(temp, 0, len - 1);

	int m, l, r;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &l, &r);
		printf("%d\n",  2 * query(t, temp, l - 1, r - 1));
	}
	return 0;
}
