#include <iostream>
#include <cstring>
using namespace std;
int m = 5, n = 5;
int main() {
    freopen("input.txt", "w", stdout);
    printf("%d %d\n", m, n);
    int l, r, val;
    for (int i = 1; i <= m; ++i) {
        l = rand() % n + 1, r = rand() % n + 1;
        if (l > r)  swap(l, r);
        val = rand() % 10 + 1;
        printf("%d %d %d\n", l, r, val);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d %d %d %d\n", rand() % n + 1, rand() % 10 + 1, rand() % 10 + 1, rand() % 10 + 1);
    }

}