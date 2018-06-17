#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int n;
bool check(string a, string b) {
	int lena = a.size(), lenb = b.size();
	if (lena > lenb)	return false;
	bool flag;
	for (int i = 0; i + lena <= lenb; ++i) {
		flag = 1;
		for (int j = 0; j < lena; ++j) {
			if (b[i + j] != a[j])	{
				flag = 0;
				break;
			}
		}
		if (flag)	return true;
	}
	return false;
}
string in[105];
int dp[105], nex[105], vis[105];
int dfs(int now) {
	if (dp[now])	return dp[now];
	dp[now] = 1;
	vis[now] = 1;
	for (int i = 1; i <= n; ++i)
		if (!vis[i] && check(in[i], in[now]))	{
			if (dp[now] < dfs(i) + 1) {
				dp[now] = dp[i] + 1;
				nex[now] = i;
			}
			vis[i] = 0;
		}
	return dp[now];
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> in[i];
}
void print(int now) {
	if (now == 0)	return ;
	print(nex[now]);
	cout << in[now] << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	input();
	for (int i = 1; i <= n; ++i) {
		if (dfs(i) == n) {
			cout << "YES\n";
			print(i);
			return 0;
		}
		vis[i] = 0;
	}

	cout << "NO\n";
}
