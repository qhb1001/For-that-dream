#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int T, len;
string a, temp;
int dp[105][105];
bool check(char aa, char bb) {
	if (aa == '[' && bb == ']')	return true;
	if (aa == '(' && bb == ')')	return true;
	return false;
}

void print(int l, int r) {
	if (l == r) {
		if (a[l] == '(' || a[r] == ')')	cout << "()";
		else	cout << "[]";
		return ;
	}	

	if (check(a[l], a[r])) {
		if (l + 1 == r)	{
			cout << a[l] << a[r];
			return ;
		} else if (dp[l][r] == dp[l + 1][r - 1]) {
			cout << a[l]; print(l + 1, r - 1); cout << a[r];
			return ;
		}
	}

	for (int k = l; k < r; ++k) {
		if (dp[l][r] == dp[l][k] + dp[k + 1][r]) {
			print(l, k); print(k + 1, r);
			return ;
		}	
	}
}

int dfs(int l, int r) {
	if (l == r)	return dp[l][l] = 1;
	if (dp[l][r] != INF)	return dp[l][r];

	if (check(a[l], a[r]))	{
		if (l + 1 == r)	return dp[l][r] = 0;
		dp[l][r] = dfs(l + 1, r - 1);
	}

	for (int k = l; k < r; ++k) {
		dp[l][r] = min(dp[l][r], dfs(l, k) + dfs(k + 1, r));
	}

	return dp[l][r];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	bool flag = 0;//是否首先输出空行
	cin >> T;
	cin.get();
	while (T--) {
		getline(cin, temp);
		getline(cin, a);

		len = a.size();
		if (len == 0)	{
			if (flag)	cout << '\n' << '\n';
			else	cout << '\n';
			flag = 1;
			continue;
		}

		memset(dp, INF, sizeof(dp));
		dfs(0, len - 1);
		//cout << dfs(0, len - 1) << '\n';
		if (flag)	cout << '\n';
		print(0, len - 1);cout << '\n';
		flag = 1;

	}
}
