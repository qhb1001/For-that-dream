#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;
int main() {
	srand((unsigned)time(NULL));
	freopen("input", "r", stdin);
	cout << 10 << " " << 100 << endl;
	for(int i = 1; i <= 10; ++i)
		cout << rand() % 1000 << " ";
	cout << endl;
}
