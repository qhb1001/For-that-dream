#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    freopen("input", "w", stdout);
    srand((unsigned)time(NULL));
    cout << 1 << endl;
    int n = 10;
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        int u = rand() % n + 1;;
        while (i == u) u = rand() % n + 1;
        bool type = rand() % 2;
        char c;
        if (type)   c = 'w';
        else    c = 'v';
        cout << u << ' ' << c << endl;
    }
}