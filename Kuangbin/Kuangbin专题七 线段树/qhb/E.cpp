#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
struct Node {
	int time, color;
}t[N];
void build(int n) {
	for(int i = 1; i <= 2 * n; ++i)
		t[i].time = 0, t[i].color = 1;
}
void update(int n, int l, int r, int color, int time) {
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)	t[l].time = time, t[l++].color = color;
		if(r&1)	t[--r].time = time, t[r].color = color;
	}
}
void push(int n) {
	for(int i = 1; i < n; ++i) {
		if(t[i].time > t[i<<1].time)	t[i<<1].color = t[i].color, t[i<<1].time = t[i].time;
		if(t[i].time > t[i<<1|1].time)	t[i<<1|1].color = t[i].color, t[i<<1|1].time = t[i].time;
	}
}
int deal(int n) {
	int ans = 0;
	for(int i = 0; i < n; ++i)
		ans += t[i + n].color;
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		int n, m, l, r, c;
		cin >> n >> m;
		build(n);
		for(int j = 1; j <= m; ++j) {
			cin >> l >> r >> c;
			update(n, l - 1, r, c, j);
		}
		push(n);
		cout << "Case " << i << ": The total value of the hook is " << deal(n) <<".\n";
	}
}
