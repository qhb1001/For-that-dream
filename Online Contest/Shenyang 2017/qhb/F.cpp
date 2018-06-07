#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const double EPS = 1e-4;
double area(double t) {
	return t * sqrt(3 * (t * t - 4)) / 4;
} 
bool equal(double a, double b) {
	if (abs(a - b) <= EPS)	return true;
	return false;
}
int deal(int n) {
	for (double i = max(3, n); ; ++i) {
		
		if (equal(area(i), (int)area(i)))	return (int)i;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 1; i <= 10000; ++i)
		cout << i << " " << deal(i) << endl;

	for (int i = 1; i <= 1000; ++i)
		if (i * i % 3 == 0)	cout << i << " " << i * i << endl;
}
