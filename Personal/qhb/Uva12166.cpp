#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
map<ll, int>mp;
string in;
int total;
void dfs(int l, int r, int depth) {
//	cout << in.substr(l, r - l + 1) << endl;
	if (in[l] == '[') {
		int cnt = 0;
		for (int i = l + 1; i < r; ++i) {
			if (in[i] == '[')	++cnt;
			else if (in[i] == ']')	--cnt;
			else if (cnt == 0 && in[i] == ',') {
				dfs(l + 1, i - 1, depth + 1);
				dfs(i + 1, r - 1, depth + 1);
				break;
			}
		}
	} else {
		ll ans = 0;
		for (int i = l; i <= r; ++i)	ans = ans * 10 + in[i] - '0';
		++mp[ans<<depth];
//		cout << (ans<<depth) << " ";
		++total;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> in;
		mp.clear();
		int len = in.size();
		total = 0;
		dfs(0, len - 1, 0);
		//cout << endl;
		int Max = 0;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			Max = max(Max, it->second);
		}
		cout << total - Max << endl;
	}
}
