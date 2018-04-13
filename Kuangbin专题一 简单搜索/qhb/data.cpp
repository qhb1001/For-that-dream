#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
int main() {
	freopen("input", "w", stdout);
	srand((unsigned)time(NULL));
	cout << rand() % 100 + 1 << " " << rand() % 100 + 1 << " " << rand() % 100 + 1 << endl;
	return 0;
}
