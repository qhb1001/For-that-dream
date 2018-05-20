#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const long long MOD = 323232323;
int G[1005][1005];
struct P {
	long long p, q;
	int l, r, y;
	void in() {
		cin >> l >> r >> y >> p >> q;
	}
}p[1005];
int cnt = 0, row, col;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> row >> col >> q;
	char type;
	while (q--) {
		cin >> type;
		if (type == 'I')	{
			++cnt;
			p[cnt].in();
			for (int i = p[cnt].l; i <= p[cnt].r; ++i) {
				G[p[cnt].y][i] = cnt;
			}
		} else if (type == 'Q') {
			int x, l, r;
			cin >> x >> l >> r;
			long long ans = 0;
			for (int i = l; i <= r; ++i)
				if (G[i][x]) {
					int now = G[i][x];
					ans = (p[now].p * ans + p[now].q) % MOD;
				}

			cout << ans << '\n';
		} else {
			int now;
			cin >> now;
			int l = p[now].l, r = p[now].r, y = p[now].y;
			for (int i = l; i <= r; ++i) 
				G[y][i] = 0;
		}
	}

}
