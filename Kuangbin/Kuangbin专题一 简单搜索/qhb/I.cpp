#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
int row, col;
const int MAX = 105;
const int INF = 1<<30;
char in[12][12], now[12][12];
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
struct Node {
	int x, y, step;
	Node(){}
	Node(int a, int b, int c): x(a), y(b), step(c){}
}tempNode, nowNode;
int bfs(int x1, int y1, int x2, int y2) {
	memcpy(now, in, sizeof(in));
	now[x1][y1] = now[x2][y2] = '.';
	int ans = 0;
	bool flag;
	queue<Node>q;
	q.push(Node(x1, y1, 0));
	q.push(Node(x2, y2, 0));
	while(q.size()) {
		while(true) {
			if(q.size() == 0 || q.front().step != ans) break;
			tempNode = q.front();q.pop();
			nowNode.step = ans + 1;
			for(int i = 0; i < 4; ++i) {
				nowNode.x = tempNode.x + X[i];
				nowNode.y = tempNode.y + Y[i];
				if(nowNode.x < 0 || nowNode.y < 0 || nowNode.x >= row || nowNode.y >= col ||
						now[nowNode.x][nowNode.y] == '.')	continue;
				q.push(nowNode);
				now[nowNode.x][nowNode.y] = '.';
			}
		}
		++ans;
	}

	for(int i = 0; i < row; ++i)
		for(int j = 0; j < col; ++j)
			if(now[i][j] == '#')	return INF;
	return ans;
}
int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		scanf("%d%d", &row, &col);
		int ans = INF;
		for(int i = 0; i < row; ++i)	scanf("%s", in[i]);

		for(int i = 0; i < row; ++i)
			for(int j = 0; j < col; ++j) {
				if(in[i][j] == '#') {
					for(int m = 0; m < row; ++m) 
						for(int n = 0; n < col; ++n) {
							if(in[m][n] == '#') {
								ans = min(ans, bfs(i, j, m, n));
							}
						}
				}
			}
		
		if(ans == INF) ans = -1;
		
		printf("Case %d: %d\n", i, ans == -1? -1 : ans - 1); 
	}
}
