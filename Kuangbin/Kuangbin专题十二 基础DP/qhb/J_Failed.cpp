#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1005;
int pre[MAX];
struct Mouse {
	int weight, speed;
	void in() {
		cin >> weight >> speed;
	}
}tempMouse, in[MAX];
int dp[MAX];
bool check(Mouse &a, Mouse &b) {
	return a.weight < b.weight && a.speed > b.speed;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = 0;
	while(cin >> in[n].weight >> in[n].speed) {
		++n;
	}
	
	memset(pre, -1, sizeof(pre));
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < i; ++j)
			if(check(in[j], in[i])) {
				if(dp[i] < dp[j] + 1)	{
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}	
			} 
	}

	int ansSum = 0, ansIdx;
	for(int i = 0; i < n; ++i)
		if(ansSum < dp[i]) {
			ansSum = dp[i];
			ansIdx = i;
		}

	cout << ansSum + 1 << '\n';
	stack<int>s;
	while(ansIdx != -1) {
		s.push(ansIdx);
		ansIdx = pre[ansIdx];
	}

	while(!s.empty())	{
		cout << s.top() << '\n';
		s.pop();
	}
	return 0;
}
