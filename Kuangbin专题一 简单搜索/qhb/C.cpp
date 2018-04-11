#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n, k;
const int MAX = 3e5 + 5;
bool vis[MAX];
struct Node {
	int idx, cost;
	Node(){}
	Node(int a, int b): idx(a), cost(b){}
}tempNode;
int  bfs() {
	queue<Node>q;
	q.push(Node(n, 0));
	while(!q.empty()) {
		tempNode = q.front();q.pop();
		if(tempNode.idx == k)	return tempNode.cost;
		if(tempNode.idx - 1 >= 0 && !vis[tempNode.idx - 1]) {
			vis[tempNode.idx - 1] = 1;
			q.push(Node(tempNode.idx - 1, tempNode.cost + 1));
		}	
		if(tempNode.idx + 1 < MAX && !vis[tempNode.idx + 1]) {
			vis[tempNode.idx + 1] = 1;
			q.push(Node(tempNode.idx + 1, tempNode.cost + 1));
		}
		if(tempNode.idx * 2 < MAX && !vis[tempNode.idx * 2]) {
			vis[tempNode.idx * 2] = 1;
			q.push(Node(tempNode.idx * 2, tempNode.cost + 1));
		}
	}
}
int main() {
	cin >> n >> k;
	cout << bfs() << endl;
	return 0;
}
