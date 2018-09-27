#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n = 6, m = 10, k = 2;
int main() {
    freopen("input.txt", "w", stdout);

    srand((unsigned)time(NULL));
    cout << n << ' ' << m << ' ' << k << endl;
    for (int i = 1; i <= n; ++i) cout << rand() % 12 + 1 << ' ' << rand() % 12 + 1 << endl;


}