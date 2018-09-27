#include <iostream>
#include <algorithm>
using namespace std;
int a[12];
int main() {
    for (int i = 1; i <= 10; ++i)   a[i] = i;
    for (int i = 1; i <= 12; ++i) cout << (lower_bound(a + 1, a + 1 + 10, i) - a) << endl;

}