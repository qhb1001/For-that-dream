#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int n, cnt = 0;
typedef long long ll;
ll cost[MAX], dp[MAX];
vector<int>G[MAX];
struct Node {
	int idx;
	ll val;
}now[MAX];


bool vis[MAX];
ll sum;
void dfs(int now) {
	if (dp[now] != -1) {
		sum += dp[now];
		return ;
	}
	int len = G[now].size();
	ll temp = 0;
	for (int i = 0; i < len; ++i) {
		if (!vis[G[now][i]]) {
			sum += cost[G[now][i]];
			vis[G[now][i]] = 1;
			dfs(G[now][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}

	cnt = n;

	for (int i = 1; i <= n; ++i) {
		now[i].idx = i;
		now[i].val = cost[i];
	}
	int k, type, nowIdx;
	ll  nowVal, l, r;
	cin >> k;

	while (k--) {
		cin >> type;
		if (type == 0) {
			cin >> nowIdx >> nowVal;
			now[nowIdx].idx = ++cnt;
		//	cout << "here " << nowIdx << " " << cnt << endl;
			now[nowIdx].val = nowVal;
			cost[cnt] = nowVal;
		} else {
			cin >> nowIdx >> l >> r;
			//cout << "here " << nowIdx << " " << now[nowIdx].idx << endl;
			for (int i = l; i <= r; ++i) {
				G[now[nowIdx].idx].push_back(now[i].idx);
		//		cout << now[i].idx << " ";
			}
		//	cout << endl;
		}
	}

	ll ans = 1e15;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= cnt; ++i) {
		memset(vis, 0, sizeof(vis));
		vis[i] = 1;
		sum = cost[i];
		dfs(i);
		dp[i] = sum;
	}

	for (int i = 1; i <= cnt; ++i)	ans = min(ans, dp[i]);
//	for (int i = 1; i <= cnt; ++i)	cout << cost[i] << " " ;
//	cout << endl;
	cout << ans << endl;
}
