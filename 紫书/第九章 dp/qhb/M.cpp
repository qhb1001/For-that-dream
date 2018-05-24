#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 205;
struct Node {
	int to, nex;
}e[MAX];
int head[MAX], cnt, idx;
map<string, int>mp;
void add(int u, int v) {
	++cnt;
	e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt;
}
int dp[2][MAX], Unique[2][MAX];//代表是否唯一
void dfs(int now) {
	int v, len = 0, Unique1 = 1, Unique2 = 1;
	dp[1][now] = 1;
	dp[0][now] = 0;
	Unique[0][now] = Unique[1][now] = 1;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		dfs(v); ++len;
		//转移选择该结点的简单情况
		dp[1][now] += dp[0][v];
		if (Unique[0][v] == 0)	Unique[1][now] = 0;

		//转移不选择该结点的情况
		dp[0][now] += max(dp[0][v], dp[1][v]);
		if (dp[0][v] == dp[1][v])	Unique[0][now] = 0;
		else if (dp[0][v] > dp[1][v] && Unique[0][v] == 0)	Unique[0][now] = 0;
		else if (dp[1][v] > dp[0][v] && Unique[1][v] == 0)	Unique[0][now] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string a, b;
	int u, v;
	while (cin >> n && n) {
		cin >> a;
		mp.clear();
		cnt = idx = 0;
		memset(head, 0, sizeof(head));
		mp[a] = ++idx;
		for (int i = 1; i < n; ++i) {
			cin >> a >> b;
			if (mp.count(b) == 0)	u = mp[b] = ++idx;
			else	u = mp[b];
			if (mp.count(a) == 0)	v = mp[a] = ++idx;
			else	v = mp[a];
			add(u, v);
		}
		dfs(1);
		int type, ans;
		if (dp[0][1] > dp[1][1])	ans = dp[0][1], type = Unique[0][1];
		else	ans = dp[1][1], type = Unique[1][1];
		if (dp[0][1] == dp[1][1])	type = 0;
		cout << ans << " ";
		if (type)	cout << "Yes\n";
		else	cout << "No\n";
	}
}
