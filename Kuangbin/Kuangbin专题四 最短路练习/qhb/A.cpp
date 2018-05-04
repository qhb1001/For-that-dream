#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 4005;
int Next[MAX], e[MAX], head[MAX], cnt = 0, cost[MAX], m, n, u, v;
void insert(int u, int v, int temp) {
	++cnt;
	e[cnt] = v;
	Next[cnt] = head[u];
	head[u] = cnt;
	cost[cnt] = temp;
}
int dis[MAX];
pair<int, int>now, temp;
int Dijkstra() {
	priority_queue<pair<int, int> >q;
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	q.push(make_pair(0, n));
	dis[n] = 0;
	while(!q.empty()) {
		temp = q.top(); q.pop();
		if(dis[temp.second] < temp.first)	continue;
		for(int i = head[temp.second]; i; i = Next[i]) {
			if(dis[e[i]] > dis[temp.second] + cost[i]) {
				dis[e[i]] = temp.first + cost[i];
				q.push(make_pair(dis[e[i]], e[i]));
			}
		}
	}
	return dis[1];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	int temp;
	for(int i = 1; i <= m; ++i) {
		cin >> u >> v >> temp;
		insert(u, v, temp);
		insert(v, u, temp);
	}
	cout << Dijkstra() << endl;

}
