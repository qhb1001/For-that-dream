#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node {
	int a[3], h;
}in[100], tempNode;
bool operator < (Node a, Node b) {
	if (a.a[1] > b.a[1] && a.a[2] > b.a[2])	return true;
	if (a.a[1] > b.a[2] && a.a[2] > b.a[1])	return true;
	return false;
}
struct edge{
	int to, nex;
}e[10000];
int head[105], idx;
void add(int u, int v) {
	++idx;
	e[idx].to = v;
	e[idx].nex = head[u];
	head[u] = idx;
}

int dp[105];
int deal(int now) {
	if (dp[now] != 0)	return dp[now];
	int Max = 0;
	for (int i = head[now]; i; i = e[i].nex) {
		Max = max(Max, deal(e[i].to));
	}
	return dp[now] = Max + in[now].h;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, kase = 1;
	while (cin >> n && n) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> tempNode.a[1] >> tempNode.a[2] >> tempNode.h;
			++cnt;
			in[cnt] = tempNode;
			++cnt;
			in[cnt].a[1] = tempNode.a[1]; in[cnt].a[2] = tempNode.h; in[cnt].h = tempNode.a[2];
			++cnt;
			in[cnt].a[1] = tempNode.a[2]; in[cnt].a[2] = tempNode.h; in[cnt].h = tempNode.a[1];
		}

		memset(head, 0, sizeof(head));
		idx = 0;
		for (int i = 1; i <= cnt; ++i) {
			for (int j = 1; j <= cnt; ++j) 
				if (i != j && in[j] < in[i])	add(i, j);
		}

		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 1;  i<= cnt; ++i)
			ans = max(ans, deal(i));

		cout << "Case " << kase++ << ": maximum height = " << ans << '\n';

	}
}
