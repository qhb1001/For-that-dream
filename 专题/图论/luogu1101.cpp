#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 105;
const int X[8] = {0, 0, 1, 1, 1, -1, -1, -1};
const int Y[8] = {1, -1, 1, 0, -1, 1, -1, 0};
char G[MAX][MAX];
const string t = "yizhong";
bool ans[MAX][MAX];
int n;
bool dfs(int x_, int y_, int dir, int cnt) {
    if (cnt == 7)   return true;
    int x = x_ + X[dir], y = y_ + Y[dir];
    if (x < 1 || y < 1 || x > n || y > n || G[x][y] != t[cnt])   return false;
    if (dfs(x, y, dir, cnt + 1))    {
        ans[x][y] = true;
        return true;
    } else {
        return false;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)    {
        scanf("%s", G[i] + 1);
    }

    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < 8; ++k) {
                if (G[i][j] == 'y') {
                    if (dfs(i, j, k, 1))    ans[i][j] = true;
                }
            }
        }
    }   


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ans[i][j])  printf("%c", G[i][j]);
            else printf("*");
        }
        printf("\n");
    }
}