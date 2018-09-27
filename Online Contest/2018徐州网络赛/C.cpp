#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#define P pair<int, int>
using namespace std;
const int t = '0' + '0' + '0';
char s[12][12];
int times1, times2;
vector<P>pos1, pos2;
bool vis[12];
double ans, now[10], fac[11], rules[100];
void dfs2(int cnt) {
    if (cnt == times2) {
        now[1] += rules[s[1][1] + s[1][2] + s[1][3] - t];
        now[2] += rules[s[2][1] + s[2][2] + s[2][3] - t];
        now[3] += rules[s[3][1] + s[3][2] + s[3][3] - t];
        now[4] += rules[s[1][1] + s[2][1] + s[3][1] - t];
        now[5] += rules[s[1][2] + s[2][2] + s[3][2] - t];
        now[6] += rules[s[1][3] + s[2][3] + s[3][3] - t];
        now[7] += rules[s[1][1] + s[2][2] + s[3][3] - t];
        now[8] += rules[s[1][3] + s[2][2] + s[3][1] - t];
        return ;
    }
    for (int i = 1; i <= 9; ++i) if (!vis[i]) {
        vis[i] = 1;
        s[pos2[cnt].first][pos2[cnt].second] = i + '0';
        dfs2(cnt + 1);
        vis[i] = 0;
    }
}
void dfs1(int cnt) {
    if (cnt == times1) {
        memset(now, 0, sizeof(now));
        dfs2(0);
        double Max = 0;
        for (int i = 1; i <= 8; ++i) Max = max(Max, now[i]);
        ans += Max;
        return ;
    }
    for (int i = 1; i <= 9; ++i) if (!vis[i]) {
        vis[i] = 1;
        s[pos1[cnt].first][pos1[cnt].second] = i + '0';
        dfs1(cnt + 1);
        vis[i] = 0;
    }
}
void init() {
    fac[0] = 1; for (int i = 1; i <= 9; ++i) fac[i] = fac[i - 1] * i;
    rules[6]=10000;rules[7]=36;rules[8]=720;rules[9]=360;
    rules[10]=80;rules[11]=252;rules[12]=108;rules[13]=72;
    rules[14]=54;rules[15]=180;rules[16]=72;rules[17]=180;
    rules[18]=119;rules[19]=36;rules[20]=360;rules[21]=1080;
    rules[22]=144;rules[23]=1800;rules[24]=3600;
}
int main() {
    int T; scanf("%d", &T); init();
    while (T--) {
        memset(vis, 0, sizeof(vis));
        times1 = times2 = 0; pos1.clear(); pos2.clear();
        for (int i = 1; i <= 3; ++i) scanf("%s", s[i] + 1);
        for (int i = 1; i <= 3; ++i) for (int j = 1; j <= 3; ++j) {
            if (s[i][j] == '*') pos1.push_back(P(i, j)), ++times1;
            else if (s[i][j] == '#')    pos2.push_back(P(i, j)), ++times2;
            else vis[s[i][j] - '0'] = 1;
        }
        ans = 0;
        dfs1(0);
        ans /= fac[times1 + times2];
        
        printf("%.7lf\n", ans);
    }
}