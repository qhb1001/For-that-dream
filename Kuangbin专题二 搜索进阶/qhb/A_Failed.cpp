#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 362880 + 5;
int fac[9];
int cantor(int a[]) {
	int ans = 0, temp;
	for(int i = 0; i < 9; ++i) {
		temp = 0;
		for(int j = i + 1; j < 9; ++j)
			if(a[i] > a[j])	++temp;
		ans += temp * fac[8 - i];
	}
	return ans + 1;
}
int preLast[MAX];
char preC[MAX];
struct Node {
	int a[9], idx;
}tempNode, nowNode;
bool bfs(int a[], int idx) {
	int last = cantor(a), now;
	queue<Node>q;
	memcpy(tempNode.a, a, sizeof(fac));
	tempNode.idx = idx;
	preC[last] = ' ';
	q.push(tempNode);
	while(!q.empty()){
		tempNode = q.front();q.pop();
		last = cantor(tempNode.a);
		if(last == 1)	return true;
		memcpy(nowNode.a, tempNode.a, sizeof(fac));
		if(tempNode.idx > 2) {
			nowNode.idx = tempNode.idx - 3;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			now = cantor(nowNode.a);
			if(preC[now] == '\0') {
				preC[now] = 'u';
				preLast[now] = last;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}

		if(tempNode.idx < 6) {
			nowNode.idx = tempNode.idx + 3;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			now = cantor(nowNode.a);
			if(preC[now] == '\0') {
				preC[now] = 'd';
				preLast[now] = last;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}

		if(tempNode.idx % 3 != 0) {
			nowNode.idx = tempNode.idx - 1;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			now = cantor(nowNode.a);
			if(preC[now] == '\0') {
				preC[now] = 'l';
				preLast[now] = last;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}

		if(tempNode.idx % 3 != 2) {
			nowNode.idx = tempNode.idx + 1;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			now = cantor(nowNode.a);
			if(preC[now] == '\0') {
				preC[now] = 'r';
				preLast[now] = last;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}
	}
	return false;
}
int main() {
	fac[0] = fac[1] = 1;
	for(int i = 2; i <= 8; ++i)	fac[i] = fac[i - 1] * i;

	char s[2];
	while(scanf("%s", s) != EOF) {
		memset(preC, 0, sizeof(preC));
		memset(preLast, 0, sizeof(preLast));
		int a[9], idx;
		if(s[0] == 'x')	a[0] = 9, idx = 0;
		else	a[0] = s[0] - '0';
		for(int i = 1; i < 9; ++i) {
			scanf("%s", s);
			if(s[0] != 'x')	a[i] = s[0] - '0';
			else	{
				a[i] = 9;
				idx = i;
			}
		}

		if(cantor(a) == 1) {
			printf("lr\n");
			continue;
		}
		if(bfs(a, idx)){
			stack<char>ans;
			int cnt = 1;
			while(preC[cnt] != ' ') {
				ans.push(preC[cnt]);
				cnt = preLast[cnt];
			}
			while(!ans.empty())	{
				printf("%c", ans.top());
				ans.pop();
			}
			printf("\n");
		} else {
			printf("unsolvable\n");
		}
	}
}
