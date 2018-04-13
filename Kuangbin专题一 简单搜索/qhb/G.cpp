#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ss1, ss2, final, now;
	int n;
	cin >> n;
	for(int k = 1; k <= n; ++k) {
		int len, ans = 0;
		cin >> len >> ss1 >> ss2 >> final;
		map<string, bool>mp;
		while(true) {
			if(now == final)	break;
			now = "";
			for(int i = 0; i < len; ++i) {
				now += ss2[i];
				now += ss1[i];
			}
			++ans;
			if(mp.count(now))	{
				ans = -1;
				break;
			}
			mp[now] = 1;
			if(now == final)	break;
			ss1 = "";
			ss2 = "";
			for(int i = 0; i < len; ++i) {
				ss1 += now[i];
				ss2 += now[len + i];
			}
		}

		cout << k << " " << ans << '\n';
	}
}
