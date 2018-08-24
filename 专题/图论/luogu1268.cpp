#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 35;
int G[MAX][MAX], n;
void input() {
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%d", &G[i][j]);
            G[j][i] = G[i][j];
        }
    }
}
int main() {
    while (scanf("%d", &n) && n) {
        input();
        int ans = G[1][2], now;
        
        for (int i = 3; i <= n; ++i) {
            now = 1<<30;
            for (int j = 2; j < i; ++j) {
                now = min(now, (G[1][i] + G[j][i] - G[1][j]) / 2);
            }
            ans += now;
        }

        printf("%d\n", ans);
    }
}