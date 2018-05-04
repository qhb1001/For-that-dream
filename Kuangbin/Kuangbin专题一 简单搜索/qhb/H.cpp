#include <iostream>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int a, b, cost;
	string path;
	Node(int a = -1, int b = -1, int c = -1) {
		this->a = a;
		this->b = b;
		this->cost = c;
	}
}tempNode, nowNode;
//represent the path  '1' for fill 1   '2' for fill 2  '3' for drop 1 '4' for drop 2
//'5' for pouring 1 to 2  '6' for pouring 2 to 1
int c, a, b;
Node pre[105][105];
void pour(bool type, int &aa, int &bb) {//'0' for pour 1 to 2,  '1' for pour 2 to 1
	if(type == 0) {
		int db = b - bb;
		if(db >= aa) {
			bb += aa;
			aa = 0;
		} else {
			aa -= db;
			bb = b;
		}
	} else {
		int da = a - aa;
		if(da >= bb) {
			aa += bb;
			bb = 0;
		} else {
			bb -= da;
			aa = a;
		}
	}
}
Node ans;
void bfs() {
	queue<Node>q;
	q.push(Node(0, 0, 0));
	pre[0][0] = Node(0, 0, 0);
	while(!q.empty()) {
		tempNode = q.front();q.pop();

	//	cout << tempNode.a << " " << tempNode.b << endl;
		if(tempNode.a == c || tempNode.b == c) {
			ans = tempNode;
			return ;
		}
		//action 1
		nowNode.a = a;nowNode.b = tempNode.b;nowNode.cost = tempNode.cost + 1;
		if(tempNode.a != a && pre[nowNode.a][nowNode.b].a == -1) {
			tempNode.path = nowNode.path = "FILL(1)";
			pre[nowNode.a][nowNode.b] = tempNode;
			q.push(nowNode);
		}

		//action 2
		nowNode.a = tempNode.a;nowNode.b = b;
		if(tempNode.b != b && pre[nowNode.a][nowNode.b].a == -1) {
			tempNode.path = nowNode.path = "FILL(2)";
			pre[nowNode.a][nowNode.b] = tempNode;
			q.push(nowNode);
		}

		//action 3
		nowNode.a = 0;nowNode.b = tempNode.b;
		if(tempNode.a != 0 && pre[nowNode.a][nowNode.b].a == -1) {
			tempNode.path = nowNode.path = "DROP(1)";
			pre[nowNode.a][nowNode.b] = tempNode;
			q.push(nowNode);
		}

		//action 4
		nowNode.a = tempNode.a;nowNode.b = 0;
		if(tempNode.b != 0 && pre[nowNode.a][nowNode.b].a == -1) {
			tempNode.path = nowNode.path = "DROP(2)";
			pre[nowNode.a][nowNode.b] = tempNode;
			q.push(nowNode);
		}

		//action 5
		nowNode.a = tempNode.a;nowNode.b = tempNode.b;
		pour(0, nowNode.a, nowNode.b);
		if(tempNode.a != 0 && tempNode.b != b && pre[nowNode.a][nowNode.b].a == -1) {
			tempNode.path = nowNode.path = "POUR(1,2)";
			pre[nowNode.a][nowNode.b] = tempNode;
			q.push(nowNode);
		}

		//action 6
		nowNode.a = tempNode.a;nowNode.b = tempNode.b;
		pour(1, nowNode.a, nowNode.b);
		if(tempNode.a != a && tempNode.b != 0 && pre[nowNode.a][nowNode.b].a == -1) {
			tempNode.path = nowNode.path = "POUR(2,1)";
			pre[nowNode.a][nowNode.b] = tempNode;
			q.push(nowNode);
		}

	}

	ans.a = -1;
	ans.b = -1;
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output.a", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);

	bfs();
	if(ans.a == -1 && ans.b == -1) {
		printf("impossible\n");
		return 0;
	}
	stack<string>final;
	printf("%d\n", ans.cost);
	ans = pre[ans.a][ans.b];
	while(true) {
		final.push(ans.path);
		if(ans.a == 0 && ans.b == 0)	break;
		ans = pre[ans.a][ans.b];
	}
	while(final.size()) {
		printf("%s\n", final.top().c_str());
		final.pop();
	}

}
