#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX = 10;
int n = MAX;

int main() {
    freopen("input", "w", stdout);
    srand((unsigned)time(NULL));
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", rand() % n + 1);
    }
}