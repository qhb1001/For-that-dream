#include <iostream>
#include <queue>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	deque<int>dq;

	dq.push_front(10);

	cout << dq.back() << endl;

	for (int i = 1; i <= 10; i += 2)	dq.push_back(i);
	for (auto it = dq.begin(); it != dq.end(); ++it)
		cout << *it << endl;
}
