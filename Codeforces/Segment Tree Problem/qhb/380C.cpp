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
	t->Left = t->Right = t->ans = 0;
	if(l == r)	{
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

Node* query(Node* t, int l, int r) {
	//cout << l << " " << r << endl;
	if(l == t->l && r == t->r) {
		return t;
	}

	int mid = (t->l + t->r) >> 1;

	if (r <= mid) return query(t->L, l, r);
	else if (l > mid)	return query(t->R, l, r);
	else {
		//只有在这个时候才需要进行合并操作
		Node* temp = (Node*)malloc(sizeof(Node));
		Node* Left = query(t->L, l, mid), * Right = query(t->R, mid + 1, r);
		int ans = min(Left->Left, Right->Right);

		temp->ans = ans + Left->ans + Right->ans;
		temp->Left = Left->Left + Right->Left - ans;
		temp->Right = Left->Right + Right->Right - ans;
		return temp;
	}
}
Node* t, *temp;
int main() {
	scanf("%s", a);
	int len = strlen(a);

	t = (Node*)malloc(sizeof(Node));
	build(t, 0, len - 1);

	int m, l, r;
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &l, &r);
		temp = query(t, l - 1, r - 1);
		printf("%d\n", temp->ans * 2);
	}
	return 0;
}
