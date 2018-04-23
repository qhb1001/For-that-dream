#include <iostream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 362880 + 5;
int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
char from[9], to[9];
int cantor(char a[]) {
	int sum = 0, temp;
	for(int i = 0; i < 9; ++i) {
		temp = 0;
		for(int j = i + 1; j <  9; ++j)
			if(a[j] < a[i])	++temp;
		sum += fac[8 - i] * temp;
	}
	return sum + 1;
}
char pre_a_c[MAX], pre_b_c[MAX];
int pre_a_last[MAX], pre_b_last[MAX];
struct Node {
	int idx, cost;
	char state[9];
	bool operator < (const Node& b) const {
		return cost > b.cost;
	}
}tempNode, nowNode;
int check(char a[]) {
	int ans = 0;
	for(int i = 0; i < 9; ++i)
		if(a[i] != to[i])
			++ans;
	return ans;
}
void bfs() {
	priority_queue<Node>a;
	memcpy(tempNode.state, from, sizeof(from));
	for(int i = 0; i < 9; ++i)	if(from[i] == 'X') {tempNode.idx = i; break;}
	tempNode.cost = check(tempNode.state);
	a.push(tempNode);
	int last, now;
	while(true) {
		if(!a.empty()) {
			tempNode = a.top(); a.pop();
			if(tempNode.cost == 0)	break;
			memcpy(nowNode.state, tempNode.state, sizeof(tempNode.state));
			last = cantor(tempNode.state);
			if(tempNode.idx < 6) {
				nowNode.idx = tempNode.idx + 3;
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
				now = cantor(nowNode.state);
				if(pre_a_last[now] == 0) {
					pre_a_last[now] = last;
					nowNode.cost = check(nowNode.state);
					pre_a_c[now] = 'd';
					a.push(nowNode);
				}
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
			}

			if(tempNode.idx % 3 != 0) {
				nowNode.idx = tempNode.idx - 1;
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
				now = cantor(nowNode.state);
				if(pre_a_last[now] == 0) {
					pre_a_last[now] = last;
					pre_a_c[now] = 'l';
					nowNode.cost = check(nowNode.state);
					a.push(nowNode);
				}
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
			}

			if(tempNode.idx % 3 != 2) {
				nowNode.idx = tempNode.idx + 1;
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
				now = cantor(nowNode.state);
				if(pre_a_last[now] == 0) {
					pre_a_last[now] = last;
					nowNode.cost = check(nowNode.state);
					pre_a_c[now] = 'r';
					a.push(nowNode);
				}
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
			}

			if(tempNode.idx > 2) {
				nowNode.idx = tempNode.idx - 3;
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
				now = cantor(nowNode.state);
				if(pre_a_last[now] == 0) {
					pre_a_last[now] = last;
					nowNode.cost = check(nowNode.state);
					pre_a_c[now] = 'u';
					a.push(nowNode);
				}
				swap(nowNode.state[nowNode.idx], nowNode.state[tempNode.idx]);
			}
		}
	}

	int cnt = cantor(to), final = cantor(from);
	stack<char>ans;
	while(cnt != final) {
		ans.push(pre_a_c[cnt]);
		cnt = pre_a_last[cnt];
	}

	printf("%d\n", ans.size());
	while(ans.size()) {
		printf("%c", ans.top());
		ans.pop();
	}
	printf("\n");
}
int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1 ;i <= T;++i){
		memset(pre_a_last, 0, sizeof(pre_a_last));
		scanf("%s%s", from, to);
		printf("Case %d: ", i);
		bfs();
	}
}
