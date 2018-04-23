#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
int row, col, bfs[2][205][205];
struct Node {
	int x, y;
	Node(int a = 0, int b = 0) {
		x = a;
		y = b;
	}
}tempNode, nowNode;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0 ,0};
char G[205][205];
void Bfs(bool type, int x, int y) {
	bfs[type][x][y] = 0;
	queue<Node>q;
	q.push(Node(x, y));
	while(q.empty() == 0) {
		tempNode = q.front();q.pop();
		for(int i = 0; i < 4; ++i) {
			nowNode.x = tempNode.x + X[i];
			nowNode.y = tempNode.y + Y[i];
			if(nowNode.x < 0 | nowNode.y < 0 || nowNode.x >= row || nowNode.y >= col ||
					bfs[type][nowNode.x][nowNode.y] != -1 || G[nowNode.x][nowNode.y] == '#' || 
					G[nowNode.x][nowNode.y] == 'M' || G[nowNode.x][nowNode.y] == 'Y')	continue;
			bfs[type][nowNode.x][nowNode.y] = bfs[type][tempNode.x][tempNode.y] + 1;
			q.push(nowNode);
		}
	}
}
int main() {
	while(scanf("%d%d", &row, &col) != EOF) {
		memset(bfs, -1, sizeof(bfs));
		for(int i = 0; i < row; ++i)	scanf("%s", G[i]);
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j) {
				if(G[i][j] == 'Y')	Bfs(0, i, j);
				if(G[i][j] == 'M')	Bfs(1, i, j);
			}

		int ans = 1<<30;
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j)
				if(G[i][j] == '@' && bfs[0][i][j] != -1 && bfs[1][i][j] != -1)
					ans = min(ans, bfs[0][i][j] + bfs[1][i][j]);
		printf("%d\n", ans * 11);
	}	
	return 0;
}
