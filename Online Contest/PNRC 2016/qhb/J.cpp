#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
struct Node {
	ll location, letters;
	bool operator < (const Node b) const {
		return location < b.location;
	}
}a[1005];

ll ans = 0, k, firstPositive;
int n;
void preTreatment() {
	sort(a + 1, a + 1 + n);
	ll temp;
	for (int i = 1; i <= n; ++i) {
		if (a[i].letters >= k) {
			temp = a[i].letters / k;
			a[i].letters -= temp * k;
			ans += abs(a[i].location) * temp;
		}
	}

	firstPositive = n + 1;
	for (int i = n; i >= 1; --i)
		if (a[i].location >= 0)	firstPositive = i;
}

void dealNegative(int tail) {
	if (tail == 0)	return ;// represent that negative value doesn't exist
	ll letterInHand = 0, l = 1;
	for (int i = 1; i <= tail; ++i) {
		letterInHand += a[i].letters;
		if (letterInHand > k) {
			a[i].letters = letterInHand - k;
			ans += -a[l].location;
			l = i;
			letterInHand = a[i].letters;
		}
		//cout << ans << endl;
	}

	if (letterInHand != 0)	ans += -a[l].location;
}

void dealPositive(int head) {
	if(head == n + 1)	return ;
	ll letterInHand = 0, r = n;
	for (int i = n; i >= head; --i) {
		letterInHand += a[i].letters;
		if (letterInHand > k) {
			a[i].letters = letterInHand - k;
			ans += a[r].location;
			r = i;
			letterInHand = a[i].letters;
		}
		//cout << ans << endl;
	}
	if (letterInHand != 0)	ans += a[r].location;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].location >> a[i].letters;
	}

	preTreatment();
	dealNegative(firstPositive - 1);
	dealPositive(firstPositive);
	cout << (ans<<1) << endl;

}
