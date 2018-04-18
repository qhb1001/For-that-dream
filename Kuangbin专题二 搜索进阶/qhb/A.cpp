#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 362880 + 5;
int fac[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int cantor(char* a) {
	int sum = 0, temp;
	for(int i = 0; i < 9; ++i) {
		temp = 0;
		for(int j = i + 1; j < 9; ++j)
			if(a[j] < a[i]) ++temp;
		sum += temp * fac[8 - i];
	}
	return sum + 1;
}
struct Node {
	char a[9];
	int idx, state;
	bool flag;// seems to be a convenient way to complete the bfs
}tempNode, nowNode;

int preLast[2][MAX];
char preC[2][MAX];
void bfs(char *from, char *to) {
	queue<Node>q;
	tempNode.flag = 1;
	memcpy(tempNode.a, from, sizeof(tempNode.a));
	for(int i = 0; i < 9; ++i) {
		if(tempNode.a[i] == 'x') {
			tempNode.idx = i;
			break;
		}
	}
	tempNode.state = cantor(tempNode.a);
	int mid = -1;//represent the break point
	q.push(tempNode);
	tempNode.flag = 0;
	preC[1][tempNode.state] = ' ';
	preC[0][1] = ' ';
	for(int i = 0; i < 8; ++i)
		tempNode.a[i] = '0' + i;
	tempNode.a[8] = 'x';
	tempNode.state = 1;
	tempNode.idx = 8;
	q.push(tempNode);

	while(!q.empty()) {
		tempNode = q.front(); q.pop();
		if(preC[!tempNode.flag][tempNode.state] != '\0') {
			mid = tempNode.state;
			break;
		}
		memcpy(nowNode.a, tempNode.a, sizeof(nowNode.a));
		nowNode.flag = tempNode.flag;

		if(tempNode.idx < 6) {
			nowNode.idx = tempNode.idx + 3;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			nowNode.state = cantor(nowNode.a);
			if(preC[nowNode.flag][nowNode.state] == '\0') {
				preC[nowNode.flag][nowNode.state] = 'd';
				preLast[nowNode.flag][nowNode.state] = tempNode.state;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}

		if(tempNode.idx % 3 != 0) {
			nowNode.idx = tempNode.idx - 1;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			nowNode.state = cantor(nowNode.a);
			if(preC[nowNode.flag][nowNode.state] == '\0') {
				preC[nowNode.flag][nowNode.state] = 'l';
				preLast[nowNode.flag][nowNode.state] = tempNode.state;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}

		if(tempNode.idx % 3 != 2) {
			nowNode.idx = tempNode.idx + 1;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			nowNode.state = cantor(nowNode.a);
			if(preC[nowNode.flag][nowNode.state] == '\0') {
				preC[nowNode.flag][nowNode.state] = 'r';
				preLast[nowNode.flag][nowNode.state] = tempNode.state;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}

		if(tempNode.idx > 2) {
			nowNode.idx = tempNode.idx - 3;
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
			nowNode.state = cantor(nowNode.a);
			if(preC[nowNode.flag][nowNode.state] == '\0') {
				preC[nowNode.flag][nowNode.state] = 'u';
				preLast[nowNode.flag][nowNode.state] = tempNode.state;
				q.push(nowNode);
			}
			swap(nowNode.a[nowNode.idx], nowNode.a[tempNode.idx]);
		}
	}

	stack<char>ans1;
	queue<char>ans2;
	int cnt = mid, temp = cantor(from);
	if(mid == -1) {
		printf("unsolvable\n");
		return ;
	}
	while(cnt != temp) {
		ans1.push(preC[1][cnt]);
		cnt = preLast[1][cnt];
	}

	cnt = mid;
	while(cnt != 1) {
		ans2.push(preC[0][cnt]);
		cnt = preLast[0][cnt];
	}

	while(!ans1.empty()) {
		printf("%c", ans1.top());
		ans1.pop();
	}
	while(!ans2.empty()) {
		printf("%c", ans2.front());
		ans2.pop();
	}
	printf("\n");
}
int main() {
	char s[2], from[9], to[9];
	while(scanf("%s", s) != EOF) {
		from[0] = s[0];
		for(int i = 1; i < 9; ++i) {
			scanf("%s", s);
			from[i] = s[0];
		}
		int preTreatment = 0;
		for(int i = 0; i < 9; ++i)
			for(int j = i + 1; j < 9; ++j)
				if(from[i] != 'x' && from[j] != 'x' && from[i] > from[j])
					++preTreatment;
		if(preTreatment % 2 == 1) {
			printf("unsolvable\n");
			continue;			
		}
		memset(preC, 0, sizeof(preC));
		memset(preLast, 0, sizeof(preLast));
		bfs(from, to);
	}
}
