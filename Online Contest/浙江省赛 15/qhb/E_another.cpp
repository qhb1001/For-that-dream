#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 1e5 + 5;
int n, f[MAX], low[MAX], up[MAX];
void in() {
	cin >> n;
	for (int i = 1; i <= n; ++i)	cin >> f[i];
	for (int i = 1; i <= n; ++i) {
		cin >> low[i] >> up[i];
	}
}
void deal() {
	int equal[MAX], less[MAX];
	for (int i = 1; i <= n; ++i) {
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
