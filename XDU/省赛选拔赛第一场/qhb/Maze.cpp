#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 105;
struct Node {
	int to;
	char c;
}tempNode;
vector<Node>G[MAX];
string op;
int n, m;
double ans = 0;
void deal(int time, int now, double p) {
	double to = 0;
	int len = G[now].size();
	if(now == n) {
		ans += p;
		return ;
	}
	if(time >= op.size())	return ;
	//查看有多少个可以走
	for (int i = 0; i < len; ++i) {
		if(G[now][i].c == op[time])	++to;
	}

	//如果不可以走，那么在这个房间呆一秒
	if (to == 0)	deal(time + 1, now, p); 
	//否则能走则走
	else {
		for (int i = 0; i < len; ++i) {
			if(G[now][i].c == op[time]) deal(time + 1, G[now][i].to, p / to);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int tempa, tempb;
	for (int i = 1; i <= m; ++i) {
		cin >> tempa >> tempb >> tempNode.c;
		tempNode.to = tempb;
		G[tempa].push_back(tempNode);
		tempNode.to = tempa;
		G[tempb].push_back(tempNode);
	}

	cin >> op;
	deal(0, 1, 1.0);
	cout << ans * 100 << endl;
}
