#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1e3 + 5;
struct Node {
	int to, nex;
}e[MAX<<2], E[MAX<<1];
int cnt, head[MAX], Head[MAX], number[MAX], low[MAX];
void add1(int u, int v) {
	++cnt;
	e[cnt].to = v;
	e[cnt].nex = head[u];
	head[u] = cnt;
}
void add2(int u, int v) {
	++cnt;
	E[cnt].to = v;
	E[cnt].nex = Head[u];
	Head[u] = cnt;
}

int belong[MAX], size[MAX], s[MAX], scc, top;
void dfs(int u) {
	number[u] = low[u] = ++cnt;
	int v;
	s[++top] = u;
	for (int i = head[u]; i; i = e[i].nex) {
		v = e[i].to;
		if (!number[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if (!belong[v]) {
			low[u] = min(low[u], number[v]);
		}
	}

	int x;
	if (low[u] == number[u]) {
		++scc;
		while (true) {
			x = s[top--];
			belong[x] = scc;
			size[scc]++;
			if (x == u)	break;
		}
	}
}

bool in[MAX];
void buildGraph() {
	cnt = 0;
	int v;
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; j; j = e[j].nex) {
			v = e[j].to;
			if (belong[v] != belong[i])	add2(belong[i], belong[v]), in[belong[v]]++;
		}
	}
}

char ans[MAX];
bool dfs1(int now, int path) {
	if (path == 3) {
		ans[now] = 'B';
		return true;
	} else if (path == 2) {
	   int cnt = 0;
		for (int i = Head[now]; i; i = E[i].nex) {
		   ++cnt;
		   dfs(E[i].to, 3);
	   }

	   if (cnt)	{
		   ans[now] = 'R';
		   return true;
	   }
		return false;
	}
	else {
	   bool flag = 0;
	   int v;
		for (int i = Head[now]; i; i = E[i].nex) {
		   v = E[i].to;
		   if (ans[v] == 'R' || dfs(v, 2))	flag = 1;
	   }
	   if (flag) {
		   ans[now] = 'W';
		   return true;
	   }
		return false;
	}
}

int main() {
	int n, m, u, v;
	char c;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%c%d", &u, &c, &v);
		add1(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!number[i])	dfs(i);
	}
	for (int i = 1; i <= scc; ++i) {
		if (in[i] == 0)	dfs1(i, 1);
	}

	for (int i = 1; i <= n; ++i) {
		if (ans[belong[i]])
	}
}
