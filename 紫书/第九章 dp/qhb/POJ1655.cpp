#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 2e4 + 5;
struct node {
	int to, nex;
}e[MAX<<1], E[MAX];
int T, cnt, head[MAX], Head[MAX], n;
void add1(int u, int v) {
	++cnt;
	e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt;
	++cnt;
	e[cnt].to = u; e[cnt].nex = head[v]; head[v] = cnt;
}
void add2(int u, int v) {
	++cnt;
	E[cnt].to = v; E[cnt].nex = Head[u]; Head[u] = cnt;
}
void getTree(int now, int fa) {
	int v;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		add2(now, v);
		getTree(v, now);
	}
}
void in() {
	cin >> n;
	cnt = 0;
	int u, v;
	memset(head, 0, sizeof(head));
	memset(Head, 0, sizeof(Head));
	for (int i = 1; i < n; ++i) {
		cin >> u >> v;
		add1(u, v);
	}

	cnt = 0;
	//默认根结点为1
	getTree(1, -1);
}

int dp[MAX], Max, idx, num;
void dfs(int now) {//在调用这个函数之前，对Max进行初始化
	int sum = 0, v, temp = 0;
	for (int i = Head[now]; i; i = E[i].nex) {
		v = E[i].to;
		dfs(v);
		if (temp < dp[v])	temp = dp[v];
		dp[now] += dp[v];
	}
	dp[now]++;
	//dp[now] 代表包括该结点及以下的子树中含有多少个结点
	temp = max(n - dp[now], temp);
	if (temp < Max) {
		Max = temp;
		idx = now;
		num = 1;
	} else if (temp == Max) {
		++num;
		if (now < idx)	idx = now;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int l = 1; l <= T; ++l) {
		memset(dp, 0, sizeof(dp));
		in();
		Max = 1<<30;
		num = 0;
		dfs(1);

//		for (int i = 1; i <= n; ++i)	cout << dp[i] << " " ;
//		cout << endl;
		cout << idx << " " << Max << '\n';
	}
}
