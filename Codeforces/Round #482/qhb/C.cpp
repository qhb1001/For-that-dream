#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
int n, x, y;
const int MAX = 3e5 + 5;
vector<int>G[MAX];
void in() {
	cin >> n >> x >> y;
	int from, to;
	for (int i = 1; i < n; ++i) {
		cin >> from >> to;
		G[from].push_back(to);
		G[to].push_back(from);
	}
}

int pre[MAX], X, Y;
bool vis[MAX];
void bfs() {
	queue<int>q;
	q.push(x);
	vis[x] = 1;
	int now, len, to;
	while (q.empty() == 0) {
		now = q.front(); q.pop();
		if (now == y)	break;
		len = G[now].size();
		for (int i = 0; i < len; ++i) {
			to = G[now][i];
			if (vis[to])	continue;
			vis[to] = 1;
			pre[to] = now;
			q.push(to);
		}
	}

	Y = pre[y];
	int cnt = y;
	while (pre[cnt] != x)	cnt = pre[cnt];
	X = cnt;
}

long long Left = 1, Right = 1;
void get() {
	memset(vis, 0, sizeof(vis));
	queue<int>q;
	q.push(x);
	vis[x] = vis[X] = 1;
	int len, now, to;
	while (q.empty() == 0) {
		now = q.front(); q.pop();
		len = G[now].size();
		for (int i = 0; i < len; ++i) {
			to = G[now][i];
			if (vis[to])	continue;
			vis[to] = 1;
			++Left;
			q.push(to);
		}
	}

	memset(vis, 0, sizeof(vis));
	q.push(y);
	vis[y] = vis[Y] = 1;
	while (q.empty() == 0) {
		now = q.front(); q.pop();
		len = G[now].size();
		for (int i = 0; i < len; ++i) {
			to = G[now][i];
			if (vis[to])	continue;
			vis[to] = 1;
			++Right;
			q.push(to);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	in();
	bfs();
	get();
	long long Mid = n - Left - Right;

	long long ans = 0;
	ans += Left * (Left - 1);
	ans += Left * Mid;
	ans += (Mid + Right) * (n - 1);
	cout << ans << endl;
}
