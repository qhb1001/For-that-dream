#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1e6 + 5;
int a[MAX];
struct Node {
	int val, idx;
	Node(int a = 0, int b = 0): val(a), idx(b) {}
}tempNode;
deque<Node>dq;
vector<int> ansMin, ansMax;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i)	cin >> a[i];
		ansMin.clear();ansMax.clear();
		dq.push_back(Node(a[1], 1));
		for (int i = 2; i <= m; ++i) {
			while (dq.size() && dq.back().val > a[i])	dq.pop_back();
			dq.push_back(Node(a[i], i));
		}
		ansMin.push_back(dq.front().val);
		for (int i = m + 1; i <= n; ++i) {
			if (dq.size() && dq.front().idx == i - m)	dq.pop_front();
			while (dq.size() && dq.back().val > a[i])	dq.pop_back();
			dq.push_back(Node(a[i], i));
			ansMin.push_back(dq.front().val);
		}

		for (int i = 0; i < ansMin.size(); ++i)	cout << ansMin[i] << " ";
		cout << endl;

		dq.clear();
		dq.push_back(Node(a[1], 1));
		for (int i = 2; i <= m; ++i) {
			while (dq.size() && dq.back().val < a[i])	dq.pop_back();
			dq.push_back(Node(a[i], i));
		}
		ansMax.push_back(dq.front().val);
		for (int i = m + 1; i <= n; ++i) {
			if (dq.size() && dq.front().idx == i - m)	dq.pop_front();
			while (dq.size() && dq.back().val < a[i])	dq.pop_back();
			dq.push_back(Node(a[i], i));
			ansMax.push_back(dq.front().val);
		}
		for(int i = 0; i < ansMax.size(); ++i)	cout << ansMax[i] << " ";
		cout << endl;
	}
}
