#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
char s[MAX];
int len;
ll power(int x) {
	ll ans = 1, base = 2;
	while (x) {
		if (x&1)	ans = ans * base % MOD;
		base = base * base % MOD;
		x >>= 1;
	}
	return ans;
}
void deal() {
	int cnt = 0;
	for (; cnt < len; ++cnt) {
		if (s[cnt] == '0' || s[cnt] == '1')	continue;
		break;
	}
	for (; cnt < len; ++cnt) {
		s[cnt] = '1';
	}
}
int main() {
//	freopen("input", "r", stdin);
//	freopen("output.a", "w", stdout);
	scanf("%s", s);
	len = strlen(s);
	deal();
	ll ans = power(len - 1);
	for (int i = 1; i < len; ++i) {
		if (s[i] == '1')	ans = (ans + power(len - 1 - i)) % MOD;
	}
	printf("%lld\n", (ans + MOD) % MOD);
}
