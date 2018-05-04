#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MAX = 100;
ll F[MAX], W[MAX], WC[MAX];
ll deal1(int n, ll num) {//num表示对应于n位的Fibonacci数，需要使用多少个数字
	if (num == 0)	return 0;
	if (num == 1)	return 1;
	if (num < F[n - 1])	return deal1(n - 1, num);//表示去掉多余的零
	else {
		num -= F[n - 1];
		return W[n - 1] + num + deal1(n - 2, num);//首先加上前面的，之后处理后面的
	}
}

ll deal2(int n, ll r, ll num) {//num表示使用了对应n位Fibonacci数，使用了多少个整数，r表示需要多少位
	if (r <= 0)	return 0;
	if (num <= F[n - 1])	return deal2(n - 1, r - 1, num);
	else	return 1 + deal2(n - 2, r - 2, num - F[n - 1]);
	//return num < F[n + 1] ? deal2(n - 1, r - 1, num): 1 + deal2(n - 2, r - 2, num - F[n + 1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("fibonacci.in", "r", stdin);
	freopen("fibonacci.out", "w", stdout);
	F[1] = W[1] = WC[1] = 1;
	for (int i = 2; i < 90; ++i) {
		F[i] = F[i - 1] + F[i - 2];
		W[i] = F[i] + WC[i - 2];
		WC[i] = WC[i - 1] + W[i];
	}
	//实际上70位的fibonacci数就够了
	ll num, ans = 0, r, n = 1;
	cin >> num;
	while (num >= n * F[n]) {
		num -= n * F[n];
		ans += W[n];
		++n;
	}

	r = num % n;
	num /= n;
	if (r != 0) {
		ans += 1;
		r -= 2;
		if (num <= F[n - 1])	ans += deal2(n - 2, r, num);
		else 	ans += deal2(n - 2, r, num - F[n - 1]);
	}
	//cout << n << " " << ans <<  " " << r <<  " " << num << endl;

	ans += deal1(n, num);
	//ans += deal2(n, r, num + F[n + 1]);
	cout << ans << endl;
}
