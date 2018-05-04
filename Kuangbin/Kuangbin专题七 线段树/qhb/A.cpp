#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 5e4;
int n, t[N];
int query(int l, int r) {
	int ans = 0;
	for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if(l&1)	ans += t[l++];
		if(r&1)	ans += t[--r];
	}
	return ans;
}
void update(int x, int add) {
	for(t[x += n] += add; x > 1; x >>= 1) {
		t[x>>1] = t[x] + t[x^1];
	}
}
void build(int n) {
	for(int i = n - 1; i > 0; --i)
		t[i] = t[i<<1] + t[i<<1|1];//because I know 'i<<1' must be even
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		cout << "Case " << i << ":" << '\n';
		cin >> n;
		for(int i = 0; i < n; ++i)	cin >> t[i + n];
		build(n);
		
		string type;
		int a, b;
		while(cin >> type && type[0] != 'E') {
			cin >> a >> b;
			if(type[0] == 'Q') {
				cout << query(a - 1, b) << '\n';
			} else if(type[0] == 'A'){
				update(a - 1, b);
			} else if(type[0] == 'S') {
				update(a - 1, -b);
			} 
		}
	}
}
