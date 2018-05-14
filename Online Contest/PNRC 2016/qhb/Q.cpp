#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, k;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll> >q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	ll now, ans = 0, T = 0;
	for (int i = 1; i <= k; ++i)	{
		cin >> now;
		q.push(now);
	}

	for (int i = k + 1; i <= n; ++i) {
		now = q.top();
		q.pop();
		T += now;
		ans += T;
		cin >> now;
		q.push(now);
	}

	while (q.size() != 0) {
		now = q.top();q.pop();
		T += now;
		ans += T;
	}

	cout << ans << endl;
}
