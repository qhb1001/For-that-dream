#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 1e5 + 5;
int n, vis[MAX], ans[MAX];
bool dfs(int idx, int len) {
	if (idx == ans[idx])	return false;
	int nexVal = n - idx + 1, nexIdx = ans[idx];
	if (vis[nexVal] || !ans[nexIdx])	return false;
	ans[nexIdx] = nexVal;
	vis[nexVal] = 1;
	if (len == n) {
		return true;
	}

	if (dfs(nexIdx, len + 1))	return true;
	else	{
		ans[nexIdx] = 0;
		vis[nexVal] = 0;
		return false;
	}
}
int ok = 0;
void print(int idx) {
	++ok;
	printf("%d ", ans[idx]);
	if (ok == n)	return ;
	print(ans[idx]);
}
int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		ans[1] = i;
		vis[1] = 1;
		if (dfs(1, 1)) {
			print(1);
			printf("\n");
			return 0;
		}
		ans[1] = 0;
		vis[1] = 0;
	}

	printf("-1\n");
	
}
