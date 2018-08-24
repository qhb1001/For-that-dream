#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 1005;
const int X[4] = {0, 0, -1, 1};
const int Y[4] = {1, -1, 0, 0};
char G[MAX][MAX];
int row, col, now, ans[MAX][MAX], n;
vector<pair<int, int> >in;
bool vis[MAX][MAX];
void bfs(int sx, int sy) {
    pair<int, int> last(sx, sy);
    queue<pair<int, int> >q;
    vis[sx][sy] = 1;
    now = 1;
    in.clear();
    in.push_back(last);
    q.push(last);
    int x, y;
    while (!q.empty()) {
        last = q.front(); q.pop();
        
        for (int i = 0; i < 4; ++i) {
            x = last.first + X[i];
            y = last.second + Y[i];
            if (x < 1 || y < 1 || x > row || y > col || vis[x][y] || G[last.first][last.second] == G[x][y]) continue;
            vis[x][y] = 1;
            ++now;
            in.push_back(make_pair(x, y));
            q.push(make_pair(x, y));
        }
    }

    int len = in.size();
    for (int i = 0; i < len; ++i) ans[in[i].first][in[i].second] = now;
}


int main() {
    int q;
    scanf("%d%d", &n, &q);
    row = col = n;
    for (int i = 1; i <= row; ++i) scanf("%s", G[i] + 1);

    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) if (!vis[i][j])  {
            bfs(i, j);
        }
    }

    int x, y;
    while (q--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", ans[x][y]);
    }
    return 0;
}
