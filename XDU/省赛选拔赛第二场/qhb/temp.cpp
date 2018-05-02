#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main() {
	map<int, int>mp;
	mp[1] = 2;
	cout << mp.count(1) << endl;
	cout << mp.count(2) << endl;

	cout << isalpha('a') << endl;
	cout << isalpha('A') << endl;
}
