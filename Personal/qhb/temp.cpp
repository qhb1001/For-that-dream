#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int>q;
	for (int i = 1; i <= 10; ++i)	q.push_back(i);

	q.clear();
	for (int i = 1; i <= 5; ++i)	q.push_back(10 - i);

	for (int i = 0; i < 10; ++i)	cout << q[i] << endl;
	
	cout << q.capacity() << endl;

	for (int i = 1; i <= 12; ++i)	q.push_back(i);
	cout << q.capacity() << endl;

	q.clear();
	cout << q.capacity() << endl;
}


