#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int row, col;
char G[105][105];
const int X[8] = {0, 0, 1, -1, -1, 1, 1, -1};
const int Y[8] = {1, -1, 0, 0, 1, 1, -1, -1};
struct Node {
	int x, y;
	Node(int xx = 0, int yy = 0): x(xx), y(yy) {}
}tempNode, nowNode;
void bfs(int x, int y) {
	queue<Node>q;
	G[x][y] = '*';
	q.push(Node(x, y));
	while(q.empty() == 0) {
		tempNode = q.front(); q.pop();
		for(int i = 0; i < 8; ++i) {
			nowNode.x = tempNode.x + X[i];
			nowNode.y = tempNode.y + Y[i];
			if(nowNode.x < 0 || nowNode.y < 0 || nowNode.x >= row || nowNode.y >= col ||
					G[nowNode.x][nowNode.y] == '*')	continue;
			G[nowNode.x][nowNode.y] = '*';
			q.push(nowNode);
		}
	} 
}
int main() {
	while(scanf("%d%d", &row, &col)) {
		if(row == 0)	break;
		for(int i = 0; i < row; ++i)	scanf("%s", G[i]);
		int ans = 0;

		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j) 
				if(G[i][j] == '@') {
					++ans;
					bfs(i, j);
				}
		printf("%d\n", ans);
	}
	return 0;
}
