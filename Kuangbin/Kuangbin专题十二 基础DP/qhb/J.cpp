#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
using namespace std;
const int MAX = 1005;
int pre[MAX], dp[MAX];
struct Mouse{
	int weight, speed;
}in[MAX];
int n = 0;
bool check(Mouse& a, Mouse &b) {
	return a.weight < b.weight && a.speed > b.speed;
}
int deal(int idx) {
	if(dp[idx] != -1)	return dp[idx];

	dp[idx] = 1;
	for(int i = 0; i < n; ++i)
		if(check(in[i], in[idx])) {
			if(deal(i) + 1 > dp[idx]) {
				dp[idx] = deal(i) + 1;
				pre[idx] = i;
			}
		}
	return dp[idx];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> in[n].weight >> in[n].speed) {
		++n;
		// if(n == 9)	break;
	}
	memset(pre, -1, sizeof(pre));
	memset(dp, -1, sizeof(dp));

	int ansSum = 0, ansIdx;
	for(int i = 0; i < n; ++i)
		if(ansSum < deal(i)) {
			ansSum = deal(i);
			ansIdx = i;
		}

	cout << ansSum << '\n';
	stack<int>s;
	while(ansIdx != -1) {
		s.push(ansIdx);
		ansIdx = pre[ansIdx];
	}

	while(!s.empty()) {
		cout << s.top() + 1<< '\n';
		s.pop();
	}
}
