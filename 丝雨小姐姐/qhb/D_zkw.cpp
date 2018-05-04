#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e6 + 5;
int Max[MAX * 2], Min[MAX * 2], n, m;
void build() {
	for(int i = n - 1; i > 0; --i) {
		Max[i] = max(Max[i<<1], Max[i<<1|1]);
		Min[i] = min(Min[i<<1], Min[i<<1|1]);
	}
}
pair<int, int> query(int l, int r) {//forget the negative value may appear
	int ansMax = -(1<<30), ansMin = 1<<30;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) {
			ansMax = max(ansMax, Max[l]);
			ansMin = min(ansMin, Min[l++]);
		}
		if (r&1) {
			ansMax = max(ansMax, Max[--r]);
			ansMin = min(ansMin, Min[r]);
		}
	}

	return make_pair(ansMin, ansMax);
}
pair<int, int>ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> n >> m) {
		for(int i = 0; i < n; ++i) {
			cin >> Max[i + n];
			Min[i + n] = Max[i + n];
		}
		build();
		vector<int>ansMax, ansMin;
		for(int i = 0; i + m <= n; ++i) {
			ans = query(i, i + m);
			ansMin.push_back(ans.first);
			ansMax.push_back(ans.second);
		}

		for(int i = 0; i < ansMin.size(); ++i)	cout << ansMin[i] << " ";
		cout << endl;
		for(int i = 0; i < ansMax.size(); ++i)	cout << ansMax[i] << " ";
		cout << endl;
	}
}
