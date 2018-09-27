#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 55;
int dp[MAX][MAX][MAX][MAX], a[MAX][MAX], row, col;
bool vis[MAX][MAX][MAX][MAX];
const int X[2] = {1, 0};
const int Y[2] = {0, 1};
struct Node {
    int x1, x2, y1, y2, val;
    Node(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
        x1 = a; y1 = b; 
        x2 = c; y2 = d;
        val = e;
    }
}now;
void bfs() {
    queue<Node>q;
    q.push(Node(1, 1, 1, 1, 0));
    vis[1][1][1][1] = 1;
    int x1, x2, y1, y2;
    while (!q.empty()) {
        now = q.front(); q.pop();

        if (dp[now.x1][now.y1][now.x2][now.y2] > now.val)   continue;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                x1 = X[i] + now.x1; x2 = X[j] + now.x2;
                y1 = Y[i] + now.y1; y2 = Y[j] + now.y2;
                if (x1 > row || x2 > row || y1 > col || y2 > col)   continue;
                if (x1 == x2 && y1 == y2) {
                    if (dp[x1][y1][x2][y2] < now.val + a[x1][y1]) {
                        dp[x1][y1][x2][y2] = now.val + a[x1][y2];
                        q.push(Node(x1, y1, x2, y2, dp[x1][y1][x2][y2]));
                    }
                } else {
                    if (dp[x1][y1][x2][y2] < now.val + a[x1][y1] + a[x2][y2]) {
                        dp[x1][y1][x2][y2] = now.val + a[x1][y1] + a[x2][y2];
                        q.push(Node(x1, y1, x2, y2, dp[x1][y1][x2][y2]));
                    }
                }
            } 
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> row >> col;
    for (int i = 1; i <= row; ++i) 
        for (int j = 1; j <= col; ++j) cin >> a[i][j];

    bfs();
    cout << dp[row][col][row][col] << endl;
}