#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	freopen("input", "w", stdout);
	cout << 1;
	for (int i = 1; i <= 10; ++i)	cout << rand() % 2;
}
