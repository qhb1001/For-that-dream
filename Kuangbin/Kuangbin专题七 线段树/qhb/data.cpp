#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	freopen("input", "w", stdout);
	cout << 10 << endl;
	for(int i = 1; i <= 10; ++i)	cout << rand() % 100 << " ";
	cout << endl;

	cout << 5 << endl;
	for(int i = 1; i <= 5; ++i) {
		cout << rand() % 2 << " " << rand() % 5 + 1 << " " << rand() % 5 + 1 << endl;
	}
}
