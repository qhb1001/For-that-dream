#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e4 + 5;
struct Node {
	int a, b, h;
	Node(int a_ = 0, int b_ = 0, int c = 0): a(a_), b(b_), h(c) {}
}nowNode;
int dp[100], n;
vector<Node>q;
int deal(int idx) {
	if(dp[idx])	return dp[idx];
	int a = q[idx].a, b = q[idx].b;
	//Maybe I can optimize the process by put dp[a][b] = dp[b][a]
	//But at first time, I dicide not to do that
	for(int i = 0; i < n; ++i) {
		if(a > q[i].a && b > q[i].b)	dp[idx] = max(dp[idx], deal(i) + q[i].h);
		if(a > q[i].b && b > q[i].a)	dp[idx] = max(dp[idx], deal(i) + q[i].h);
	}
	return dp[idx];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1;; ++i) {
		cin >> n;
		if(!n)	break;
		//initialization
		memset(dp, 0, sizeof(dp));
		int a, b, c;
		q.clear();
		for(int i = 1; i <= n; ++i) {
			cin >> a >> b >> c;
			q.push_back(Node(a, b, c));
			q.push_back(Node(a, c, b));
			q.push_back(Node(b, c, a));
		}
		n *= 3;

		int ans = 0;
		for(int i = 0; i < n; ++i)
			ans = max(ans, deal(i) + q[i].h);
		cout << "Case " << i << ": maximum height = " << ans << '\n';
	}
}
