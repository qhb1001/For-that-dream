#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int N = 8e4 + 5;
const int MAX = 8e4 + 1;
int color[N];
struct Node {
	int color, time;
}t[N<<1];
void build() {
	for(int i = 1; i < (N<<1); ++i)
		t[i].color = -1, t[i].time = 0;
}
void update(int l, int r, int color, int time) {
	for(l += MAX, r += MAX; l < r; l >>= 1, r >>= 1) {
		if(l&1)	t[l].color = color, t[l++].time = time;
		if(r&1)	t[--r].color = color, t[r].time = time;
	}
}
void push() {
	for(int i = 1; i < MAX; ++i) {
		if(t[i].time > t[i<<1].time)	t[i<<1].time = t[i].time, t[i<<1].color = t[i].color;
		if(t[i].time > t[i<<1|1].time)	t[i<<1|1].time = t[i].time, t[i<<1|1].color = t[i].color;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, l, r, c;
	while(cin >> m) {
		build();
		for(int i = 1; i <= m; ++i) {
			cin >> l >> r >> c;
			update(l, r, c, i);
		}
		push();
		memset(color, 0, sizeof(color));
		int now = -1;
		for(int i = 0 + MAX; i <= MAX + MAX; ++i) {
			if(now == -1) {
				if(t[i].color == -1)	continue;
				now = t[i].color;
			} else {
				if(t[i].color == now)	continue;
				else {
					color[now]++;
					now = t[i].color;
				}
			}
		}

		for(int i = 0; i < MAX; ++i)
			if(color[i])	cout << i << " " << color[i] << '\n';
		cout << '\n';
	}
}
