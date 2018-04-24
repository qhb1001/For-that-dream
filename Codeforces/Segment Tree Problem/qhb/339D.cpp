#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = (1<<18) + 5;
int t[MAX], n;
int getHeight(int x) {
	int ans = 0;
	while (x < n) {
		x <<= 1;
		++ans;
	}
	return ans;
}
void build() {
	for (int i = n - 1; i > 0; --i) {
		if(getHeight(i) % 2 == 1)	t[i] = t[i<<1] | t[i<<1|1];
		else	t[i] = t[i<<1] ^ t[i<<1|1];
	}
}
void update(int i, int x) {
	for	(t[i += n] = x; i > 1; i >>= 1) {
		if(getHeight(i) % 2 == 0)	t[i>>1] = t[i] | t[i^1];
		else	t[i>>1] = t[i] ^ t[i^1];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> n >> m;
	n = 1<<n;
	for(int i = 0; i < n; ++i)	cin >> t[i + n];
	build();
	
	int a, b;
	while (m--) {
		cin >> a >> b;
		update(a - 1, b);
		cout << t[1] << '\n';
	}
}
