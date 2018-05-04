#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
struct Node{
	int val, idx;
	Node(int a = 0, int b = 0): val(a), idx(b) {}
	bool operator < (const Node& b) const {
		return idx < b.idx;
	}
}tempNode;
const int MAX = 5e4 + 5;
int a[MAX];
stack<int>Stack[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	set<int>s;
	s.insert(1);
	s.insert(2);
	cout << (s.find(3) == s.end()) << endl;
}
