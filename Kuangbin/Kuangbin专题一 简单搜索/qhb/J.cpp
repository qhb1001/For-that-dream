#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int row, col;
char G[1005][1005];
struct Node {
	int x, y, step;
	char c;
	Node(){}
	Node(int a, int b, int c, char cc): x(a), y(b), step(c), c(cc){}
}tempNode, nowNode;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
queue<Node>q;
int bfs() {
	int now = 1;
	while(q.empty() == 0) {
		while(true) { 
			if(q.front().step != now)	break;
			tempNode = q.front();q.pop();
			if(tempNode.c == 'J' && G[tempNode.x][tempNode.y] == 'J') {
				for(int i = 0; i < 4; ++i) {
					nowNode.x = tempNode.x + X[i];
					nowNode.y = tempNode.y + Y[i];
					if(nowNode.x < 0 || nowNode.y < 0 || nowNode.x == row || nowNode.y == col )	return now;
					if(G[nowNode.x][nowNode.y] != '.')	continue;
					G[nowNode.x][nowNode.y] = 'J';
					q.push(Node(nowNode.x, nowNode.y, now + 1, 'J'));
				}
			}
			if(tempNode.c == 'F') {
				for(int i = 0; i < 4; ++i) {
					nowNode.x = tempNode.x + X[i];
					nowNode.y = tempNode.y + Y[i];
					if(nowNode.x < 0 || nowNode.y < 0 || nowNode.x >= row || nowNode.y >= col ||
							G[nowNode.x][nowNode.y] == '#' || G[nowNode.x][nowNode.y] == 'F') continue;
					G[nowNode.x][nowNode.y] = 'F';
					q.push(Node(nowNode.x, nowNode.y, now + 1, 'F'));
				}
			}
		}
		++now;
	}
	return -1;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		while(q.size())	q.pop();
		scanf("%d%d", &row, &col);
		for(int i = 0; i < row; ++i)	scanf("%s", G[i]);
		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j) {
				if(G[i][j] == 'F')	q.push(Node(i, j, 1, 'F'));
				if(G[i][j] == 'J')	q.push(Node(i, j, 1, 'J'));
			}

		int ans = bfs();
		if(ans == -1)	printf("IMPOSSIBLE\n");
		else	printf("%d\n", ans);
	}
	return 0;
}
