#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int from, to;
const int MAX = 1e5;
bool vis[MAX];
struct Node {
	int val, step;
	Node(int a = 0, int b = 0): val(a), step(b) {}
}tempNode, nowNode;
int init = 0;
int bfs() {
	queue<Node>q;
	q.push(Node(from, init));
	vis[from] = 1;
	while(!q.empty()) {
		tempNode = q.front(); q.pop();
		if(tempNode.val == to)	return tempNode.step;
		if(tempNode.val * 2 <= to * 2 && !vis[tempNode.val * 2]) {
			vis[tempNode.val * 2] = 1;
			q.push(Node(tempNode.val * 2, tempNode.step + 1));
		}
		if(tempNode.val - 1 >= 1 && tempNode.val - 1 >= to / 2 && !vis[tempNode.val - 1]) {
			vis[tempNode.val - 1] = 1;
			q.push(Node(tempNode.val - 1, tempNode.step + 1));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> from >> to;
	while(true) {
		if(from <= to * 2 && from >= to / 2)	break;
		if(from > to)	from -= 1;
		else	from *= 2;
		init++;
	}
	cout << bfs() << endl;
}
