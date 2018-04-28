#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
struct Node {
	string now;
	struct Node *L, *R;
};

string in;
void build(Node*& t, int l, int r) {
	cout << l << " " << r << endl;
	t->now = "";
	if (r - l <= 4) {
		bool flag = 0;
		for (int i = l; i < r; ++i) {
			t->now += in[i];
			if (in[i] == '(' || in[i] == ')' || in[i] == ',')	{
				flag = 1;
				break;
			}
		}
		
		if (!flag) {
			t->L = t->R = NULL;
			return ;
		}
	}

	t->now = "";
	int p = 0;
	//首先读入根结点对应的串
	while (in[l] != '(')	t->now += in[l++];
	++l;

	//寻找中间逗号所在的位置
	int cnt;
	for (int i = l; i < r; ++i) {
		if (in[i] == '(')	++p;
		else if (in[i] == ')')	--p;
		else if (in[i] == ',' && !p)	{
			cnt = i;
			break;
		}
	}

	t->L = (Node*)malloc(sizeof(Node));
	t->R = (Node*)malloc(sizeof(Node));
	build(t->L, l, cnt);
	build(t->R, cnt + 1, r);
}

void pre(Node*& t) {
	if (t->L == NULL && t->R == NULL)	{
		cout << t->now;
		return ;
	}
	cout << t->now << "(";pre(t->L);cout << ",";pre(t->R);cout << ")";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Node* t = (Node*)malloc(sizeof(Node));
	cin >> in;
	build(t, 0, in.size() - 1);
	pre(t);
	cout << endl;
}
