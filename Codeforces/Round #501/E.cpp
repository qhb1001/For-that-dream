#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 1005;
int row, col, l[MAX][MAX], r[MAX][MAX], up[MAX][MAX], down[MAX][MAX];
char mp[MAX][MAX];
void input() {
    cin >> row >> col;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            cin >> mp[i][j];
        }
    }

    //left side
    for (int i = 1; i <= row; ++i)
    for (int j = 1; j <= col; ++j) {
        if (mp[i][j] == '.')    l[i][j] = 0;
        else    l[i][j] = l[i][j - 1] + 1;
    }

    //right side
    for (int i = 1; i <= row; ++i)
    for (int j = col; j >= 1; --j) {
        if (mp[i][j] == '.')    r[i][j] = 0;
        else    r[i][j] = r[i][j + 1] + 1;
    }

    //up side
    for (int i = 1; i <= row; ++i)
    for (int j = 1; j <= col; ++j) {
        if (mp[i][j] == '.')    up[i][j] = 0;
        else    up[i][j] = up[i - 1][j] + 1;
    }

    //down side
    for (int i = row; i >= 1; --i)
    for (int j = 1; j <= col; ++j) {
        if (mp[i][j] == '.') down[i][j] = 0;
        else    down[i][j] = down[i + 1][j] + 1;
    }
}

struct Star {
    int x, y, len;
    Star(int a = 0, int b = 0, int c = 0): x(a), y(b), len(c) {}
};
vector<Star>star;//to store the cordination of the star

void deal() {
    int len;
    for (int i = 1; i <= row; ++i) 
    for (int j = 1; j <= col; ++j) {
        len = min(min(l[i][j], r[i][j]), min(up[i][j], down[i][j]));
        --len;
        if (len == 0 || len == -1)   continue;
        star.push_back(Star(i, j, len));
    }
}

void change(int x, int y, int len) {
    const int X[4] = {0, 0, 1, -1};
    const int Y[4] = {1, -1, 0, 0};
    mp[x][y] = '.';
    for (int i = 0; i < 4; ++i) {
        for (int k = 1; k <= len; ++k) {
            mp[x + X[i] * k][y + Y[i] * k] = '.';
        }
    }
}
bool check() {
    int len = star.size();
    for (int i = 0; i < len; ++i)   change(star[i].x, star[i].y, star[i].len);
    
    for (int i = 1; i <= row; ++i)
    for (int j = 1; j <= col; ++j)
    if (mp[i][j] != '.')    return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    deal();
    if (!check()) cout << -1 << endl;
    else {
        int len = star.size();
        cout << len << endl;
        for (int i = 0; i < len; ++i)
        cout << star[i].x << ' ' << star[i].y << ' ' << star[i].len << endl;
    }
}