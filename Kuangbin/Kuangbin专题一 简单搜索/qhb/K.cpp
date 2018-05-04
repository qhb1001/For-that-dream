#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int x, y, cost;
	Node(int a = -1, int b = -1, int c = -1): x(a), y(b), cost(c) {}
}tempNode, nowNode;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
Node pre[7][7];
int G[10][10], row = 5, col = 5;
void bfs() {
	queue<Node>q;
	q.push(Node(0, 0, 0));
	pre[0][0].x = 0;
	while(q.empty() == 0) {
		tempNode = q.front();q.pop();
		for(int i = 0; i < 4; ++i) {
			nowNode.x = tempNode.x + X[i];
			nowNode.y = tempNode.y + Y[i];
			if(nowNode.x < 0 || nowNode.y < 0 || nowNode.x >= row || nowNode.y >= col ||
					G[nowNode.x][nowNode.y] == 1 || pre[nowNode.x][nowNode.y].x != -1)	continue;
			pre[nowNode.x][nowNode.y] = tempNode;
			nowNode.cost = tempNode.cost + 1;
			q.push(nowNode);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			cin >> G[i][j];
	bfs();
	stack<Node>s;
	nowNode = Node(4, 4);
	while(true) {
		s.push(nowNode);
		if(nowNode.x == 0 && nowNode.y == 0)	break;
		nowNode = pre[nowNode.x][nowNode.y];
	}

	while(s.size()) {
		cout << "(" << s.top().x << ", " << s.top().y << ")\n";
		s.pop();
	}
	return 0;
}
