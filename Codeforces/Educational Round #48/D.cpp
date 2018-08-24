#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
int row[105], r[105];
int col[105], c[105];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)    cin >> row[i];
    for (int j = 1; j <= m; ++j)    cin >> col[j];
    memcpy(r, row, sizeof(row));
    memcpy(c, col, sizeof(col));
}

int ans[105][105];
void pretreatment() {
    int t;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
        t = row[i] & col[j];
        ans[i][j] = t;
        row[i] ^= t;
        col[j] ^= t;
    }
}

void deal() {
    int t;
    for (int i = 1; i < m; ++i) 
    for (int j = i + 1; j <= m; ++j) {
        t = col[i] & col[j];
        if (t == 0) continue;
        col[i] ^= t;
        col[j] ^= t;
        ans[1][i] ^= t;
        ans[1][j] ^= t;
        if (col[i] == 0)    break;
    }

    for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) {
        t = row[i] & row[j];
        if (t == 0) continue;
        row[i] ^= t;
        row[j] ^= t;
        ans[i][1] ^= t;
        ans[j][1] ^= t;
        if (row[i] == 0)    break; 
    }
}

bool check() {
    int now = 0;
    for (int i = 1; i <= n; ++i) {
        now = 0;
        for (int j = 1; j <= m; ++j) {
            now ^= ans[i][j];
        }
        if (now != r[i])  return false;
    }

    for (int i = 1; i <= m; ++i) {
        now = 0;
        for (int j = 1; j <= n; ++j) {
            now ^= ans[j][i];
        }
        if (now != c[i])    return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    pretreatment();
    deal();
    if (check() == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)    cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
}