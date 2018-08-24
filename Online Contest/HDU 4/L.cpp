#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int a, b;
        scanf("%d", &a);
        b = a;
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &b);
            // printf("%d\n", b);
        }
        int temp = abs(a - b);
        printf("%d\n", (int)sqrt(temp * 1.0));
    }

}