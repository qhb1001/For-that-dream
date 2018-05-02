#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	freopen("input", "w", stdout);
	int n = 15, x1 = rand() % 100, x2 = rand() % 1000;
	cout << n << " " << x1 << " " << x2 << endl;

	for (int i = 1; i <= n; ++i)	cout << rand() % 100 << " ";
	cout << endl;
}
