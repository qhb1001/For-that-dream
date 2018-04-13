#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
struct Node {
	int l[3], step;
	Node(int aa = 0, int bb = 0, int cc = 0, int dd = 0) {
		l[0] = aa;
		l[1] = bb;
		l[2] = cc;
		step = dd;
	}
}tempNode, nowNode;
int L[4];
bool vis[105][105][105];
void pour(bool type, int idx1, int idx2) {
	if(type == 0) {//pour from idx1 to idx2
		int dx = L[idx2] - nowNode.l[idx2];
		if(nowNode.l[idx1] > dx) {
			nowNode.l[idx2] = L[idx2];
			nowNode.l[idx1] -= dx;
		} else {
			nowNode.l[idx2] += nowNode.l[idx1];
			nowNode.l[idx1] = 0;
		}
	} else {
		int dx = L[idx1] - nowNode.l[idx1];
		if(nowNode.l[idx2] > dx) {
			nowNode.l[idx1] = L[idx1];
			nowNode.l[idx2] -= dx;
		} else {
			nowNode.l[idx1] += nowNode.l[idx2];
			nowNode.l[idx2] = 0;
		}
	}
}
int bfs() {
	memset(vis, 0, sizeof(vis));
	queue<Node>q;
	vis[L[0]][0][0] = 1;
	q.push(Node(L[0], 0, 0, 0));
	while(q.empty() == 0) {
		tempNode = q.front(); q.pop();
		if(tempNode.l[0] == tempNode.l[1] && tempNode.l[0] + tempNode.l[1] == L[0])	return tempNode.step;
		if(tempNode.l[0] == tempNode.l[2] && tempNode.l[0] + tempNode.l[2] == L[0])	return tempNode.step;
		if(tempNode.l[1] == tempNode.l[2] && tempNode.l[1] + tempNode.l[2] == L[0])	return tempNode.step;
		nowNode = tempNode;
		pour(0, 0, 1);
		if(!vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]]) {
			vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]] = 1;
			nowNode.step = tempNode.step + 1;
			q.push(nowNode);
		}

		nowNode = tempNode;
		pour(1, 0, 1);
		if(!vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]]) {
			vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]] = 1;
			nowNode.step = tempNode.step + 1;
			q.push(nowNode);
		}

		nowNode = tempNode;
		pour(0, 0, 2);
		if(!vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]]) {
			vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]] = 1;
			nowNode.step = tempNode.step + 1;
			q.push(nowNode);
		}

		nowNode = tempNode;
		pour(1, 0, 2);
		if(!vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]]) {
			vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]] = 1;
			nowNode.step = tempNode.step + 1;
			q.push(nowNode);
		}

		nowNode = tempNode;
		pour(0, 1, 2);
		if(!vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]]) {
			vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]] = 1;
			nowNode.step = tempNode.step + 1;
			q.push(nowNode);
		}

		nowNode = tempNode;
		pour(1, 1, 2);
		if(!vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]]) {
			vis[nowNode.l[0]][nowNode.l[1]][nowNode.l[2]] = 1;
			nowNode.step = tempNode.step + 1;
			q.push(nowNode);
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> L[0] >> L[1] >> L[2]) {
		if(L[0] == 0)	break;
		int ans = bfs();
		if(ans == -1) cout << "NO\n";
		else	cout << ans << endl;
	}
}
