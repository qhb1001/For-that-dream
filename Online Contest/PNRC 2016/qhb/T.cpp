#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int row, col;
string G[55];
struct Node {
	int x, y;
	Node(int a = 0, int b = 0) :x(a), y(b) {}
}tempNode, nowNode;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
int cnt = 0;
bool vis[55][55];
void bfs(int nowx, int nowy) {
	queue<Node>q;
	q.push(Node(nowx, nowy));
	vis[nowx][nowy] = 1;
	while (q.empty() == 0) {
		tempNode = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			nowNode.x = tempNode.x + X[i];
			nowNode.y = tempNode.y + Y[i];
			if (nowNode.x < 0 || nowNode.x >= row || nowNode.y < 0 || nowNode.y >= col 
					|| vis[nowNode.x][nowNode.y] || G[nowNode.x][nowNode.y] == 'W')	continue;
			G[nowNode.x][nowNode.y] = 'L';
			vis[nowNode.x][nowNode.y] = 1;
			q.push(nowNode);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> row >> col;
	for (int i = 0; i < row; ++i)	cin >> G[i];
	
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j) {
			if (G[i][j] == 'L' && vis[i][j] == 0) {
				++cnt;
				bfs(i, j);
			}
		}
	cout << cnt << endl;
}
