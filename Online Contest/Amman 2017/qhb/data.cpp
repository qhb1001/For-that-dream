#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	freopen("input", "w", stdout);
	cout << 1 << endl;
	int n = rand() % 50 + 1, k = rand() % 10 + 1;
	cout << n << " " << k << endl;
	for (int i = 1; i <= n; ++i)
		cout << rand() % 100 + 1 << " ";

}
