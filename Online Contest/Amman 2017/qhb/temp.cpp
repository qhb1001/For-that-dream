#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
struct Node {
	int val;
	bool operator < (const Node b) const {
		return val > b.val;
	}
}a[12];
int main() {
	srand((unsigned)time(NULL));
	for (int i = 1; i <= 10; ++i) {
		a[i].val = rand() % 100;
	}
	
	sort(a + 1, a + 11, [] (Node a, Node b) {
				return a.val < b.val;
			});
	for (int i = 1; i <= 10; ++i)	cout << a[i].val << " ";
	cout << endl;
}
