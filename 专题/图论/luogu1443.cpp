#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 405;
int ans[MAX][MAX], row, col;
const int X[10] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
const int Y[10] = {0, 2, -2, 2, -2, 1, -1, 1, -1};

void bfs(int sx, int sy) {
    queue<pair<int, int> >q;
    q.push(make_pair(sx, sy));
    memset(ans, -1, sizeof(ans));
    ans[sx][sy] = 0;
    int x, y;
    pair<int, int> now;
    while (!q.empty()) {
        now = q.front(); q.pop();
        for (int i = 1; i <= 8; ++i) {
            x = now.first + X[i];
            y = now.second + Y[i];
            if (x < 1 || y < 1 || x > row || y > col || ans[x][y] != -1) continue;
            ans[x][y] = ans[now.first][now.second] + 1;
            q.push(make_pair(x, y));
        }
    }
    for (int i = 1; i <= row; ++i){ 
        for (int j = 1; j <= col; ++j) {
            printf("%-5d", ans[i][j]);
        }
        printf("\n");
    }
}

void solve() {
    scanf("%d%d", &row, &col);
    int x, y;
    scanf("%d%d", &x, &y);
    bfs(x, y);
}

int main() {
    solve();
}