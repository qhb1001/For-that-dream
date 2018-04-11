#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;
bool check(int x) {
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0)	return false;
	return true;
}
vector<int>prime;

bool check(int a, int b) {
	int dif = 0;
	while(a) {
		if(a % 10 != b % 10) ++dif;
		a /= 10;
		b /= 10;
	}
	if(dif == 1)	return true;
	return false;
}
vector<int>G[10000];
void preTreatment() {
	int len = prime.size();
	for(int i = 0; i < len; ++i) {
		for(int j = 0; j < len; ++j)
			if(check(prime[i], prime[j])) {
				G[prime[i]].push_back(prime[j]);
				G[prime[j]].push_back(prime[i]);
			}
	}
}
struct Node {
	int cost, idx;
	Node() {}
	Node(int a, int b): idx(a), cost(b){}
}tempNode, nowNode;

int bfs(int from, int to) {
	queue<Node>q;
	q.push(Node(from, 0));
	bool vis[10005] = {0};
	vis[from] = 1;
	
	while(q.empty() == 0) {
		tempNode = q.front();q.pop();
		if(tempNode.idx == to)	return tempNode.cost;
		for(int i = 0; i < G[tempNode.idx].size(); ++i) {
			nowNode.idx = G[tempNode.idx][i];
			if(vis[nowNode.idx])	continue;
			vis[nowNode.idx] = 1;
			nowNode.cost = tempNode.cost + 1;
			q.push(nowNode);
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 1000; i <= 9999; ++i)
		if(check(i))
			prime.push_back(i);
	preTreatment();
	int n, a, b;
	cin >> n;
	while(n--) {
		cin >> a >> b;
		if(a == b) {
			cout << 0 << '\n';
			continue;
		}
		int ans = bfs(a, b);
		if(ans == -1)	cout << "Impossible\n";
		else	cout << ans << '\n';
	}

}
