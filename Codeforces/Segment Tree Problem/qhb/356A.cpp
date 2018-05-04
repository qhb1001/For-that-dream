#include <iostream>
#include <cstring>
using namespace std;
const int MAX = (3e5 + 5) * 2;
int n, m;
struct Node {
	int val, time;//val 被谁打败   time 染色的时间   初始的时候两者都是0
}t[MAX], tempNode;
//初始化线段树
void build() {
	for (int i = 1; i <= 2 * n; ++i) {
		t[i].val = t[i].time = 0;
	}
}

//结点染色
//数值如果不等于0，那么就不能染色
void update(int l, int r, int x, int time) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) {
			if(t[l].time == 0) {
				t[l].time = time;
				t[l].val = x;
			}
			++l;
		}
		if (r&1) {
			--r;
			if(t[r].time == 0) {
				t[r].time = time;
				t[r].val = x;
			}
		}
	}
}

//向上回溯，找到最大的颜色标记
//需要特殊处理的是那个没有被染色的结点，它路径上的颜色均为0
//这样一想，其实必须使用大值代表时间更早
int find(int x) {
	tempNode.val = tempNode.time = 0;
	for(x += n; x > 0; x >>= 1) {
		if (tempNode.time < t[x].time) {
			tempNode.time = t[x].time;
			tempNode.val = t[x].val;
		}
	}
	return tempNode.val;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	build();

	int l, r, x;
	for(; m >= 1; --m) {
		cin >> l >> r >> x;
		--l;--r;
		if (x - 1 == l)	update(l + 1, r + 1, x, m);
		else if (x - 1== r)	update(l, r, x, m);
		else {
			update(l, x - 1, x, m);
		//	cout << l << " " << x - 1 << " to " << x << endl;
			update(x, r + 1, x, m);
		//	cout << x + 1 << " " << r << " to " << x << endl;
		}
	}

	for(int i = 1; i <= n; ++i)	cout << find(i - 1) << " ";
	cout << '\n';
}
