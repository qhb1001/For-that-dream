#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
multiset<int>s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, in;
	cin >> n;
	while (n--) {
		cin >> k;
		for (int i = 1; i <= k; ++i) {
			cin >> in;
			s.insert(in);
		}
		auto aa = s.begin(), bb = s.end();
		--bb;
		int a = *aa, b = *bb;
		cout << a << " " << b << '\n';
		s.erase(s.lower_bound(a));
		s.erase(s.lower_bound(b));
	}
	return 0;
}
