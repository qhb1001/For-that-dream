#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1e5 + 5;
int n, f[MAX], low[MAX], ans[MAX];
void in() {
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> f[i];
	int temp;
	for (int i = 1; i <= n; ++i) {
		cin >> low[i] >> temp;
	}
}
void deal1() {
	int idxOfEqual[MAX] = {0};
	for (int i = n; i >= 1; --i) {
		ans[i] = low[i];
		if (idxOfEqual[f[i]])	ans[i] = max(ans[i], ans[idxOfEqual[f[i]]]);
		idxOfEqual[f[i]] = i;
	}
}
void deal2() {
	int idxOfLess[MAX] = {0};
	for (int i = 1; i <= n; ++i) {
		if (idxOfLess[f[i] - 1])	ans[i] = max(ans[i], ans[idxOfLess[f[i] - 1]] + 1);
		idxOfLess[f[i]] = i;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		in();
		deal1();
		deal2();
		cout << ans[1];
		for (int i = 2; i <= n; ++i)	cout << " " << ans[i];
		cout << endl;
	}
}
