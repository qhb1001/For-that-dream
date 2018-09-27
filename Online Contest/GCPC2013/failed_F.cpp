#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 12;
char G[MAX][MAX];
int idx[MAX][MAX];
vector<pair<int, int> >chess;
bool drop[MAX];
int len, ans, row = 5, col = 9;
const int X[4] = {0, 0, 1, -1};
const int Y[4] = {1, -1, 0, 0};
bool flag;

void dfs(int cnt) {
//    printf("..........%d..........\n", cnt);
//    for (int i = 1; i <= row; ++i) {
//        for (int j = 1; j <= col; ++j) cout << G[i][j];
//        cout << endl;
//    }
    if (flag)   return ;
    ans = max(ans, cnt);
    pair<int, int> now;
    int x, y, xx, yy;
    if (ans == len - 1) {flag = true; return ;}
    for (int i = 0; i < len; ++i) if (!drop[i]) {
        for (int j = 0; j < 4; ++j) {
            x = chess[i].first + X[j];
            y = chess[i].second + Y[j];
            xx = x + X[j];
            yy = y + Y[j];
            if (x < 0 || y < 0 || x > row || y > col || G[x][y] != 'o')   continue;
            if (xx < 0 || yy < 0 || xx > row || yy > col || G[xx][yy] != '.')   continue;
            if (drop[idx[x][y]])    continue;
            
            swap(idx[chess[i].first][chess[i].second], idx[xx][yy]);
            swap(G[chess[i].first][chess[i].second], G[xx][yy]);
            now = chess[i];
            chess[i].first = xx; chess[i].second = yy;
            drop[idx[x][y]] = 1;
            G[x][y] = '.';
            
            dfs(cnt + 1);
            
            chess[i] = now;
            G[x][y] = 'o';
            drop[idx[x][y]] = 0;
            swap(G[chess[i].first][chess[i].second], G[xx][yy]);
            swap(idx[chess[i].first][chess[i].second], idx[xx][yy]);
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("ouput.txt", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 5; ++i) scanf("%s", G[i] + 1);
        chess.clear(); len = 0; ans = 0; flag = false; memset(idx, 0, sizeof(idx));
        for (int i = 1; i <= row; ++i) for (int j = 1; j <= col; ++j) if (G[i][j] == 'o')   {chess.push_back(make_pair(i, j)); ++len; idx[i][j] = len - 1;}
        dfs(0);
        printf("%d %d\n", len - ans, ans);
    }
}
