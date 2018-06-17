#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int a[105];
vector<int>ans;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		a[x] = i;
	}
	

	for (int i = 1; i <= 100; ++i) {
		if (a[i])	ans.push_back(a[i]);
	}

	int len = ans.size();
	if (len >= k) {
		cout << "YES\n";
		for (int i = 0; i < k; ++i)	cout << ans[i] << " ";
	} else	cout << "NO\n";
}
