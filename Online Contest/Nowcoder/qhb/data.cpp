#include <iostream>
#include <ctime>
#include <algorithm>
#include <set>
using namespace std;
int a[150000];
set<int>s;
int main() {
	srand((unsigned)time(NULL));
	int n = rand() % 10 + 1;
	int d = rand() % 10000 + 1;
	freopen("input", "w", stdout);
	cout << n << " " << d << endl;
	for (int i = 1; i <= n; ++i) {
		int now = rand() % 10000 - 100;
		while (s.find(now) != s.end())	now = rand() % 10000 - 100;
		s.insert(now);
		a[i] = now;
	}
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i)	cout << a[i] <<  " ";
} 
