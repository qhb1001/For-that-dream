#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 6005;
int n, val[MAX];
struct Node {
    int to, nex;
}e[MAX], E[MAX];//e for undirected graph   E for rooted graph
int heade[MAX], headE[MAX], cnt;
int max(int a, int b) {
	if (a > b)	return a;
	return b;
}
void add1(int u, int v) {
    ++cnt;
    e[cnt].to = v;
    e[cnt].nex = heade[u];
    heade[u] = cnt;

    ++cnt;
    e[cnt].to = u;
    e[cnt].nex = heade[v];
    heade[v] = cnt;
}

void add2(int u, int v) {
    ++cnt;
    E[cnt].to = v;
    E[cnt].nex = headE[u];
    headE[u] = cnt;
}

int root;
bool vis[MAX];
void getTree(int now) {
    int v;
    vis[now] = 1;
    for (int i = heade[now]; i; i = e[i].nex) {
        v = e[i].to;
        if (vis[v])    continue;
        vis[v] = 1;
        add2(now, v);
        getTree(v);
    }
}
void in() {
    int u, v;
    for (int i = 1; i <= n; ++i)    cin >> val[i];

    cnt = 0;
    while (cin >> u >> v && u) {
        add2(v, u);
		vis[u] = v;
    }

	for (int i = 1; i <= n; ++i)
		if (vis[i] == 0)	{
			root = i;
			return ;
		}
}
void print(int now) {
    cout << now << endl;
    for (int i = headE[now]; i; i = E[i].nex) {
        print(E[i].to);
    }
    cout << now << endl;
}
int dp[2][MAX];
#define INF 0x3f3f3f3f
int dfs(bool flag, int now) {
    if (dp[flag][now] != INF)    return dp[flag][now];

    //如果该点需要选取的话
    int v;
    if (flag) {
        dp[flag][now] = val[now];
        for (int i = headE[now]; i; i = E[i].nex) {
            v = E[i].to;
            if (dfs(0, v) > 0)    dp[flag][now] += dfs(0, v);//如果不选下一个点，可以得到正值的话
        }
        return dp[flag][now];
    }

    //如果该点不需要选取的话
    dp[flag][now] = 0;
    int temp;
    for (int i = headE[now]; i; i = E[i].nex) {
        v = E[i].to;
        temp = max(dfs(0, v), dfs(1, v));//下一个结点取或者不取均可
        if (temp >= 0)    dp[flag][now] += temp;//事实上似乎不加这个if也可以
    }
    return dp[flag][now];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        memset(dp, INF, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        memset(headE, 0, sizeof(headE));
        in();
        //print(root);
        cout << max(dfs(0, root), dfs(1, root)) << '\n';
    }
}
