#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
struct Node {
	int l, r;//表示该结点对应的区间
	int idxl, idxr;//表示子序列最大值对应的区间	
	int Left;//表示包含左边界的最大和
	int Right;//表示包含有边界的最大和
	ll ans, ansl, ansr;
	struct Node* L, *R;
}tempNode;
const int MAX = 5e4 + 5;
ll a[MAX];
void combine(Node*& aa, Node*& b) {
	tempNode.ans = aa->ans;
	//首先从两个区间的最大值转移而来
	if (aa->idxr + 1 == b->idxl) {
		tempNode.ans = max(tempNode.ans, aa->ans + b->ans);
		tempNode.idxl = aa->idxl;
		tempNode.idxr = b->idxr;
	} else {
		if (aa->ans > b->ans) {
			tempNode.ans = aa->ans;
			tempNode.idxl = aa->idxl;
			tempNode.idxr = aa->idxr;
		} else {
			tempNode.ans = b->ans;
			tempNode.idxl = b->idxl;
			tempNode.idxr = b->idxr;
		}
	}

	//更新tempNode.ansl
	int cnt = aa->l + 1;
	ll sum = tempNode.ansl = a[aa->l];
	while (cnt <= b->r) {
		sum += a[cnt];
		if (sum > tempNode.ansl) {
			tempNode.ansl = sum;

		}
	}
}
void build(int l, int r, Node*& t) {
	if (l == r) {
		t->l = t->r = l;
		t->ans = t->ansl = t->ansr = a[l];
		t->Right = t->Left = t->idxl = t->idxr = l;
		return ;
	}

	int mid = (l + r) >> 1;
	t->L = new Node;
	t->R = new Node;
	build(l, mid, t->L);
	build(mid + 1, r, t->R);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Node* root = new Node;
	
}
