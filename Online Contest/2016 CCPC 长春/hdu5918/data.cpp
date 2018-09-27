#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAX = 12;
int main() {
    freopen("input.txt", "w", stdout);
    srand((unsigned)time(NULL));
    int n = MAX, m = 2;
    printf("%d\n%d %d %d\n", 1, n, m, rand() % (n>>1) + 1);
    
    for (int i = 1; i <= n; ++i)    printf("%d ", rand() % 3 + 1);
    printf("\n");
    for (int i = 1; i <= m; ++i)    printf("%d ", rand() % 3 + 1);
}