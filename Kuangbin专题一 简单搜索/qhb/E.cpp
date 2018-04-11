#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll ans = -1, in;
bool vis[22];
void dfs(int idx) {
	if(ans != -1)	return ;
	if(idx == 19) {
		ll now = 0;
		for(int i = 0; i < 19; ++i)
			now = now * 10 + vis[i];
		if(now < in)	return ;
		if(now % in == 0)	{
			ans = now;
		}
		return ;
	}
	for(int i = idx; i < 19; ++i) {
		vis[i] = 1;
		dfs(i + 1);
		vis[i] = 0;
		dfs(i + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> in && in) {
		ans = -1;
		dfs(0);
		cout << ans << '\n';		
	}

}
