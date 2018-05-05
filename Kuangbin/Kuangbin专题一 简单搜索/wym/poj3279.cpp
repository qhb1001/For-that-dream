#include<cstdio>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
int map[20][20];
bool current[20][20];
bool a[20][20];
int dir[5][2] = { { -1, 0 }, { 1, 0 }, { 0, 0 }, { 0, -1 }, { 0, 1 } };
int ans = INF;
int n, m;
bool getcolor(int x, int y) {
    int res = map[x][y];
    for (int i = 0; i < 5; i++){
        int fx = x + dir[i][0], fy = y + dir[i][1];
        if (fx >= 1 && fx <= n && fy >= 1 && fy <= m) res += current[fx][fy];
    }
    return res % 2;
}
int solve(){
    int res = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (getcolor(i - 1, j)) current[i][j] = 1;
    for (int i = 1; i <= m; i++)
        if (getcolor(n, i)) return INF;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res += current[i][j];
    return res;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);
    for (int s = 0; s < 1 << m; s++){
        memset(current, false, sizeof(current));
        for (int i = 1; i <= m; i++)
            current[1][i] = s >> (m - i) & 1;
        int t = solve();
        if (t < ans){
            ans = t;
            memcpy(a, current, sizeof(current));
        }
    }
    if (ans == INF) printf("IMPOSSIBLE\n");
    else{
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
