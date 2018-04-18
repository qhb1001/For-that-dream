#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e5;
bool vis[MAX];
struct Node {
	int val, step;
	Node(int a = 0, int b = 0) {
		val = a;
		step = b;
	}
}tempNode, nowNode;
int from, to;
int bfs(){
	queue<Node>q;
	q.push(Node(from, 0));
	while(!q.empty()) {
		tempNode = q.front(); q.pop();
		if(tempNode.val == to)	return tempNode.step;
		nowNode.val = tempNode.val * 2;
		nowNode.step = tempNode.step + 1;
		if(nowNode.val < MAX && !vis[nowNode.val]) {
			vis[nowNode.val] = 1;
			q.push(nowNode);
		}
		nowNode.val = tempNode.val - 1;
		if(nowNode.val > 0 && !vis[nowNode.val]) {
			vis[nowNode.val] = 1;
			q.push(nowNode);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> from >> to;
	cout << bfs() << endl;
}
