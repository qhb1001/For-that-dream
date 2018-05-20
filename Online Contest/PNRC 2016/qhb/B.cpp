#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
map<ll, int>mp;
int cnt;
const int MAX = 1<<15;
vector<int>G[MAX];
ll barbell[20], plate[20];
vector<ll>ok;//表示可以达成的哑铃重量
set<ll>ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	cin >> barbell[i];
	for (int i = 1; i <= m; ++i)	cin >> plate[i];

	ll now;
	int idx;
	for (int i = 1; i < (1<<m); ++i) {
		now = 0;
		for (int j = 1; j <= m; ++j) {
			if (i & (1<<(j - 1)))	now += plate[j];
		}
		if (mp.count(now) == 0)	{
			idx = ++cnt;
			mp[now] = idx;
		} else	idx = mp[now];

		G[idx].push_back(i);
	}

	int len, temp;
	bool flag;
	for (int i = 1; i <= cnt; ++i) {
		len = G[i].size();
		flag = 0;
		for (int j = 0; j < len; ++j) {
			for (int k = j + 1; k < len; ++k) {
				if ((G[i][j] & G[i][k]) == 0) {
					flag = 1;
					temp = G[i][j];
					break;
				}
			}
			if (flag)	break;
		}

		if (flag)	{
			now = 0;
			for (int j = 1; j <= m; ++j) {
				if (temp & (1<<(j - 1)))	now += plate[j];
			}
			ok.push_back(now * 2);
		}
	}

	//现在ok保存的是所有可以达成的哑铃数量
	ok.push_back(0);
	len = ok.size();

	for (int i = 0; i < len; ++i) {
		for (int j = 1; j <= n; ++j)
			ans.insert(barbell[j] + ok[i]);
	}

	for (set<ll>::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << '\n';
	}
}
