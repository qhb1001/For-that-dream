#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 5e5 + 5;
int f[MAX], n;

void Ins(int x, int y) {
    x += n + 1;
    for (; x <= 2 * n + 3; x += x & -x) {
        cout << (x & -x) << ' ' << x << endl;
    }
}
int main() {

    n = 1000;
    Ins(100, 1);
}