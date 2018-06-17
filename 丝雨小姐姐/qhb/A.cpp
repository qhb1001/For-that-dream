#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
struct Node {
	ll val;
	int idx;
	Node(ll a = 0, int b = 0): val(a), idx(b) {}
};
deque<Node>q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, A, B;
	while (cin >> n >> A >> B) {
		ll ans = 1, now = 1;
		q.clear();
		for (int i = 1; i <= min(A + 1, n); ++i) {
			now = now * A % B;
			while (q.empty() == 0 && q.back().val > now)	q.pop_back();
			q.push_back(Node(now, i));
			ans = ans * q.front().val % B;
		}

		for (int i = min(A + 1, n) + 1; i <= n; ++i) {
			now = now * A % B;
			while (q.empty() == 0 && q.back().val > now)	q.pop_back();
			while (q.empty() == 0 && q.front().idx < i - A)	q.pop_front();
			q.push_back(Node(now, i));
			ans = ans * q.front().val % B;
		}
		cout << ans << '\n';
	}
}
