#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e6 + 5;
long long t[2][N<<1];
int n, idx[N];
struct Node {
	int idx, val;
	bool operator < (const Node& b) const {
		return val < b.val;
	}
}a[N];

//离散化处理
void deal() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].val;
		a[i].idx = i;
	}
	sort(a + 1, a + 1 + n);

	int cnt = 1;
	idx[a[1].idx] = 1;
	for(int i = 2; i <= n; ++i)
		idx[a[i].idx] = ++cnt;
}


//只有对于第二棵线段树的build函数
void build() {
	for(int i = N - 1; i > 0; --i)
		t[1][i] = t[1][i<<1] + t[1][i<<1|1];
}

void update(int type, int i, int val) {
	for (t[type][i += N] += val; i > 1; i >>= 1) {
		t[type][i>>1] = t[type][i] + t[type][i^1];
	}
}

//两颗线段树都有查询操作
long long query(int type, int l, int r) {
	long long ans = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if(l&1)	ans += t[type][l++];
		if(r&1)	ans += t[type][--r];
	}
	return ans;
}

long long first[N];//逆序对数组
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	deal();
	for(int i = n; i >= 1; --i) {
		first[i] = query(0, 0, idx[i]);
		update(0, idx[i], 1);
	}

	//for (int i = 1; i <= n; ++i)
	//	cout << first[i] << " ";
	//cout << endl;
	long long ans = 0;
	for (int i = n; i >= 1; --i) {
		ans += query(1, 0, idx[i]);
		update(1, idx[i], first[i]);
	}

	cout << ans << '\n';

}
