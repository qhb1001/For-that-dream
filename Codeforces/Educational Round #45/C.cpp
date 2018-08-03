#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
const int MAX = 3e5 + 5;
typedef long long ll;
ll l[MAX], r[MAX], zero;
ll update(string &in) {
	int len = in.size();
	int ll = 0, rr = 0;
	for (int i = 0; i < len; ++i) {
		if (in[i] == '(')	++ll;
		else {
			if (ll)	--ll;
			else	++rr;
		}
	}

	if (ll == 0 && rr)	++r[rr];
	else if (ll && rr == 0)	++l[ll];
	else if (ll == 0 && rr == 0)	++zero;

	if (ll == 0 && rr)	return l[rr];
	if (ll && rr == 0)	return r[ll];
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string in;
	ll ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> in;
		ans += update(in);
	}
	ans += zero * zero;
	cout << ans << endl;
}

