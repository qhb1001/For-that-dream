#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 105;
int cnt, row, col, head[MAX * MAX], vis[MAX * MAX], match[MAX * MAX];
bool G[MAX][MAX];
struct Node {
	int to, nex;
}e[MAX*MAX*4];
void add(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}
void in() {
	cin >> row >> col;
	int k, v, u;
	cin >> k;
	while (k--) {
		cin >> u >> v;
		G[u][v] = 1;
	}
	for (int i = 1; i <= row; ++i)
		for (int j = 1; j <= col; ++j) {
			if (G[i][j])	continue;
			if (j != 1)	add(i * row + j - row, i * row + j - 1 - row);
			if (j != col)	add(i * row + j - row, i * row + j + 1 - row);
			if (i != 1)	add(i * row + j - row, (i - 1) * row + j - row);
			if (i != row)	add(i * row + j - row, (i + 1) * row + j - row);
		}
}
bool dfs(int now) {
	vis[now] = 1;
	int v;
	for (int i = head[now]; i; i = e[i].nex) {
		v = e[i].to;
		if (vis[v])	continue;
		if (!match[v] || dfs(match[v])) {
			match[v] = now;
			return true;
		}
	}
	return false;
}
int hungarian() {
	int ans = 0;
	for (int i = 1; i <= 
			; ++i) {
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
}
