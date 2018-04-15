#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
struct Node {
	string name;
	int deadline, days;
	void in() {
		cin >> name >> deadline >> days;
	}
}homework[20];
struct State {
	string path;
	int cost;
}dp[32768 + 5], tempState;
void init(int n) {
	for(int i = 0; i < n; ++i) {
		homework[i].in();
	}
	for(int i = 0; i < (1<<n); ++i)
		dp[i].cost = -1;
}
void bfs(int n) {
	dp[0].path = "";
	dp[0].cost = 0;
	queue<int>q;
	q.push(0);
	int last, now, sumDay, nowDay;
	while(!q.empty()) {
		last = q.front();q.pop();
		sumDay = 0;
		for(int i = 0; i < n; ++i) 
			if(last & (1<<i))
				sumDay += homework[i].days;
		for(int i = 0; i < n; ++i) {
			if(!(last & (1<<i))) {
				now = last | (1<<i);
				nowDay = sumDay + homework[i].days;
				tempState.path = dp[last].path + (char)('0' + i);
				tempState.cost = dp[last].cost;
				tempState.cost += homework[i].deadline > nowDay? 0 : nowDay - homework[i].deadline;
				if(dp[now].cost == -1)	q.push(now);
				if(dp[now].cost == -1 || dp[now].cost > tempState.cost || 
						(dp[now].cost == tempState.cost && tempState.path < dp[now].path)) {
					dp[now] = tempState;
				}
			}
		}
	}

	int final = (1<<n) - 1;
	cout << dp[final].cost << '\n';
	for(int i = 0; i < n; ++i)
		cout << homework[dp[final].path[i] - '0'].name << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		string temp;
		int n;
		cin >> n;
		init(n);
		bfs(n);	
	}
}
