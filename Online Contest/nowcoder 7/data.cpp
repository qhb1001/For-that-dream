#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
const int MAX = 1000;
char s[MAX + 5][MAX + 5];
int n, m;
int main() {
    freopen("input.txt", "w", stdout);
    srand((unsigned)time(NULL));
    n = rand() % MAX + 1; m = rand() % MAX + 1;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (rand() % 2 == 1) {
                printf("%c", 'A' + rand() % 26);
            } else {
                printf("%c", 'a' + rand() % 26);
            }
        }
        printf("\n");
    }
}