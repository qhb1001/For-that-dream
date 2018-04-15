#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, temp;
	while(cin >> n) {
		q.clear();
		for(int i = 1; i <= n; ++i)	{
			cin >> temp;
			q.push_back(temp);
		}
		sort(q.begin(), q.end());
		int cnt = 1;
		for(int i = 1; i < n; ++i)
			if(q[i] == q[i - 1])	++cnt;
			else {
				if(cnt > n / 2)	{
					cout << q[i - 1] << '\n';
					cnt = 1;
					break;
				}
				cnt = 1;

			}

		if(cnt > n / 2)	cout << q[n - 1] << '\n';
	}
	return 0;
}
