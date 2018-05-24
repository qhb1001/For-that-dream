#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 11111;
typedef long long ll;
struct Node {
	int to, nex, w;
}e[MAX<<1];
int head[MAX], cnt, son[MAX], dp[3][MAX];
int max(int a, int b) {
	if (a > b)	return a;
	return b;
}
void add(int u, int v, int w) {
	++cnt;
	e[cnt].w = w; e[cnt].to = v; e[cnt].nex = head[u]; head[u] = cnt;
}
void init() {
	cnt = 0;
	memset(dp, 0, sizeof(dp));
	memset(head, 0, sizeof(head));
}
void dfs1(int now, int fa) {
	int v;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		dfs1(v, now);
		if (dp[0][v] + e[i].w >= dp[0][now]) {
			dp[1][now] = dp[0][now];
			son[now] = v;
			dp[0][now] = dp[0][v] + e[i].w;
		}
		else if (dp[0][v] + e[i].w > dp[1][now]) dp[1][now] = dp[0][v] + e[i].w;
		else if (dp[1][v] + e[i].w > dp[1][now]) dp[1][now] = dp[1][v] + e[i].w;
	}
}
void dfs2(int now, int fa) {
	int v;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (v == fa)	continue;
		if (son[now] == v) {//如果当前结点的最长路经过v结点
			dp[2][v] = max(dp[1][now], dp[2][now]) + e[i].w;
		} else {
			dp[2][v] = max(dp[0][now], dp[2][now]) + e[i].w;
		}
		dfs2(v, now);
	}
}
int main() {
	int n, u, v, w;
	while (scanf("%d", &n) != EOF) {
		init();
		for (int i = 2; i <= n; ++i)	{
			scanf("%d%d", &v, &w);
			//add(i, v, w);
			add(v, i, w);//把这一行注释掉之后WA，不注释则A
		}
		dfs1(1, -1);
		dfs2(1, -1);
		for (int i = 1; i <= n; ++i)
			printf("%d\n", max(dp[0][i], dp[2][i]));
	}
	return 0;
}
