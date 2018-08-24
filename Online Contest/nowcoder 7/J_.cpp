#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 1000;
char s[MAX + 5][MAX + 5];
int n, m;
map<char, int> mp;
bool check(int x, int y, int xx, int yy) {
    int e1 = xx - x + 1, e2 = yy - y + 1;
    if (e1 * e2 > 52)   return false;   
    if (xx - x + 1 > 52)    return false;
    if (yy - y + 1 > 52)    return false;

    bool vis[55] = {0};
    for (int i = x; i <= xx; ++i) 
    for (int j = y; j <= yy; ++j) {
        if (vis[mp[s[i][j]]])   return false;
        vis[mp[s[i][j]]] = 1;
    }
    return true;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.b", "w", stdout);
    int cnt = 1;
    for (char c = 'a'; c <= 'z'; ++c) {
        mp[c] = cnt++;
        mp[c - 32] = cnt++;
    }
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)    scanf("%s", s[i] + 1);

    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int i_ = i; i_ <= n; ++i_) {
                for (int j_ = j; j_ <= m; ++j_) {
                    if (check(i, j, i_, j_)) {
                        ++ans;
                        // printf("%d %d %d %d\n", i, j, i_, j_);
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}