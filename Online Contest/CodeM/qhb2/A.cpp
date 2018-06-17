#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
string G[5][5];
bool vis[5][5];
int dis[100][100];
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
struct Node {
	int x, y, step;
	Node(int a = 0, int b = 0, int c = 0) {
		x = a;
		y = b;
		step = c;
	}
}nowNode, nexNode;
void bfs(int nowX, int nowY, char now) {
	string temp;
	memset(vis, 0, sizeof(vis));
	vis[nowX][nowY] = 1;
	queue<Node>q;
	q.push(Node(nowX, nowY, 0));
	int x, y;
	while (!q.empty()) {
		nowNode = q.front(); q.pop();
		temp = G[nowNode.x][nowNode.y];
		for (int i = 0; i < temp.size(); ++i) {
			dis[now][temp[i]] = nowNode.step;
		}

		for (int i = 0; i < 4; ++i) {
			x = nowNode.x + X[i];
			y = nowNode.y + Y[i];
			if (x < 1 || y < 1 || x > 3 || y > 3 || vis[x][y])	continue;
			vis[x][y] = 1;
			q.push(Node(x, y, nowNode.step + 1));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	G[1][1] = "@!:"; G[1][2] = "ABC"; G[1][3] = "DEF"; 
	G[2][1] = "GHI"; G[2][2] = "JKL"; G[2][3] = "MNO";
	G[3][1] = "PQRS"; G[3][2] = "TUV"; G[3][3] = "WXYZ";


	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= 3; ++j) {
			string temp = G[i][j];
			for (int k = 0; k < temp.size(); ++k)
				bfs(i, j, temp[k]);
		}

	int T;
	cin >> T;
	while (T--) {
		string now;
		cin >> now;
		char cnt = '!';
		int ans = 0;
		for (int i = 0; i < now.size(); ++i) {
			ans += dis[cnt][now[i]];
			cnt = now[i];
		}
		cout << ans << '\n';
	}
}
