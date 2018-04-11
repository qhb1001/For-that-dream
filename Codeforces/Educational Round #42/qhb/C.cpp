#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
string a;
int len;
map<long long, bool>mp;
const long long MAX = 2e9 + 5;
typedef long long ll;
bool vis[12];
int ans_num = 0;
void update() {
	int now = 0;
	for(int i = 0; i < len; ++i)
		if(!vis[i])	++now;
	if(ans_num < now)	ans_num = now;
}
bool check() {
	ll ans = 0;
	for(int i = 0; i < len; ++i)
		if(!vis[i]) {
			if(a[i] == '0')	return false;
			else	break;
		}
	
	for(int i = 0; i < len; ++i)
		if(!vis[i]) ans = ans * 10 + a[i] - '0';
	if(mp.count(ans) == 0)	return false;
	return true;
}
void dfs(int idx) {
	if(idx == len) {
		if(check())	update();
		return ;
	} 
	for(int i = idx; i < len; ++i) {
		vis[i] = 1;
		dfs(i + 1);
		vis[i] = 0;
		dfs(i + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a;
	len = a.size();
	
	ll now = 1;
	while(now * now <= MAX) {
		mp[now * now] = 1;
		++now;
	}
	if(check())	{
		cout << 0 << endl;
		return 0;
	}

	dfs(0);
	if(ans_num == 0)	cout << -1 << endl;
	else cout << len - ans_num << endl;
	
}
