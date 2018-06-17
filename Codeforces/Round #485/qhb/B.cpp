#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {

	int x, y;
	cin >> x >> y;
	if (y * log10(x) < x * log10(y))	cout << '<';
	else if (y * log10(x) > x * log10(y))	cout << '>';
	else	cout << '=';
}
