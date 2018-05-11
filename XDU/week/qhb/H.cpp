#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans = 0;
typedef long long ll;
ll n;
void dfs(ll now) {
	if (now <= n)	++ans;
	if (now > n)	return ;
	
	dfs(now * 10);
	dfs(now * 10 + 1);
}
int main() {
	freopen("input", "r", stdin);
	freopen("output.b", "w", stdout);
	cin >> n;
	dfs(1LL);
	cout << ans << '\n';
}
