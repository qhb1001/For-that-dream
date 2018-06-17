#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, string>mp;
map<string, bool>vis;
vector<string>ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["purple"] = "Power";
	mp["green"] = "Time";
	mp["blue"] = "Space";
	mp["orange"] = "Soul";
	mp["red"] = "Reality";
	mp["yellow"] = "Mind";
	string a[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		string temp;
		cin >> temp;
		vis[mp[temp]] = 1;
	}
	for (int i = 0; i < 6; ++i) {
		if (vis.count(a[i]) == 0) {
			ans.push_back(a[i]);
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
}
