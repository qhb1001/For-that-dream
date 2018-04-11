#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int MAX = 1e5 + 5e4 + 5;
map<int, int>mp;
priority_queue<int, vector<int>, greater<int> >q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i <= 10; ++i)	q.push(i);
	while(q.empty() == 0) {
		cout << q.top();
		q.pop();
	}
	return 0;
}
