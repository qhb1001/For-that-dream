#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b, c;
    while (cin >> a >> b >> c) {
        printf("%.5lf\n", b*(b-1)/((a+b)*(a+b-c-1)) + a*b/(((a+b)*(a+b-c-1))));
    }
}