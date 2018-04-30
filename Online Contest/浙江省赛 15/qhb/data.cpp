#include <iostream>
#include <ctime>
using namespace std;
struct Node {
	int type, val;
	bool operator < (const Node &b) const {
		if (type != b.type)	return type < b.type;
		return val < b.val;
	}
}a[15];
bool vis[15][15];
int main() {
	freopen("input", "w", stdout);
	srand((unsigned)time(NULL));
	cout << 1 << endl;
	int n = 10, m = 9;
	cout << n << " " << m << endl;

	for (int i = 1;  i<= 10; ++i)	{
		a[i].type = rand() % 3 + 1;
		a[i].val = rand() % 9 + 1;
		while (vis[a[i].type][a[i].val]) {
			a[i].type = rand() % 3 + 1;
			a[i].val = rand() % 9 + 1;
		}
		vis[a[i].type][a[i].val] = 1;
	}

	sort(a + 2, a + 1 + 10);
	int idx = rand() % 8 + 2;
	for (int i = 1; i <= 10; ++i) {
		if (i == idx) {
			cout << "W\n";
			continue;
		}
		if (a[i].type == 1)	cout << "C " << a[i].val << '\n';
		else if (a[i].type == 2)	cout << "B " << a[i].val << '\n';
		else	cout << "D " << a[i].val << '\n';
	}
}
