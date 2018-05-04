#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, x, h, MAX, ans;
struct Node {
	int x1, x2, h;
	void in() {
		cin >> x1 >> x2 >> h;
	}
	bool operator < (const Node &b) const {
		return h > b.h;
	}
}tempNode;
int dp[1005][2];
vector<Node>q;
//initialization for the initial drop position
void init() {
	int i;
	for(i = 0; i < n; ++i) {
		if(h - q[i].h > MAX)	break;
		if(q[i].x1 <= x && q[i].x2 >= x) {
			dp[i][0] = x - q[i].x1 + h - q[i].h;
			dp[i][1] = q[i].x2 - x + h - q[i].h;
			break;
		}
	}
	if(i == n)	ans = h;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, nowx, nowh, j, temp;
	cin >> T;
	while(T--) {
		q.clear();
		cin >> n >> x >> h >> MAX;
		for(int i = 0; i < n; ++i) {
			tempNode.in();
			q.push_back(tempNode);
		}
		sort(q.begin(), q.end());
		memset(dp, -1, sizeof(dp));
		ans = 1<<30;
		init();
		for(int i = 0; i < n; ++i) {
			//transfer the left state
			nowx = q[i].x1;
			nowh = q[i].h;
			if(dp[i][0] != -1) {
				//n should be checked specially
				for(j = i + 1; j < n; ++j)
					if(nowx <= q[j].x2 && nowx >= q[j].x1 && nowh - q[j].h <= MAX) {
						temp = nowx - q[j].x1 + nowh - q[j].h + dp[i][0];
						if(dp[j][0] == -1)	dp[j][0] = temp;
						else	dp[j][0] = min(dp[j][0], temp);
						temp = q[j].x2 - nowx + nowh - q[j].h + dp[i][0];
						if(dp[j][1] == -1)	dp[j][1] = temp;
						else	dp[j][1] = min(dp[j][1], temp);
						break;
					}
				if(j == n && nowh <= MAX)	ans = min(ans, dp[i][0] + nowh);
			}

			nowx = q[i].x2;
			if(dp[i][1] != -1) {
				for(j = i + 1; j < n; ++j)
					if(nowx <= q[j].x2 && nowx >= q[j].x1 && nowh - q[j].h <= MAX) {
						temp = dp[i][1] + nowx - q[j].x1 + nowh - q[j].h;
						if(dp[j][0] == -1)	dp[j][0] = temp;
						else	dp[j][0] = min(dp[j][0], temp);
						temp = dp[i][1] + q[j].x2 - nowx + nowh - q[j].h;
						if(dp[j][1] == -1)	dp[j][1] = temp;
						else	dp[j][1] = min(dp[j][1], temp);
						break;
					}
				if(j == n && nowh <= MAX)	ans = min(ans, dp[i][1] + nowh);
			}
		}

		cout << ans << '\n';
	}
}
