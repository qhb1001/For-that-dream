#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
	int to, nex;
}e[MAX];
int head[MAX], cnt, T;
void add(int u, int v) {
	++cnt;
	e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt;
}
int dp[MAX];//记录该结点也申请工资时需要的花费
int dfs(int now) {
	dp[now] = 0;
	vector<int>cost;
	int v, len = 0;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		dfs(v);
		++len;
		cost.push_back(dp[v]);
	}
	
	if (len == 0)	return dp[now] = 1;
	int need = ceil(len * T / 100.0);
	sort(cost.begin(), cost.end());
	for (int i = 0; i < need; ++i)
		dp[now] += cost[i];

	return dp[now];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n >> T && n) {
		cnt = 0;
		memset(head, 0, sizeof(head));
		int u, v;
		for (int i = 1; i <= n; ++i) {
			cin >> u;
			add(u, i);
		}
		cout << dfs(0) << '\n';
	}

}
