#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 605;
typedef long long ll;
struct Point {
    int id;
    ll x, y;
    bool operator < (const Point b) const {
        return y * b.x >= x * b.y;
    }  
    Point(int a = 0, ll b = 0, ll c = 0): id(a), x(b), y(c) {}
}point[MAX<<1];
ll dp[MAX<<1][MAX<<1], cost[MAX];
int l[MAX], r[MAX], n, cnt;
void input() {
    scanf("%d", &n);
    cnt = 0;
    ll L, R, H, W;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld%lld%lld", &H, &L, &R, &W);
        point[++cnt] = Point(i, L, H);
        point[++cnt] = Point(i, R, H);
        cost[i] = W;
    }

    sort(point + 1, point + 1 + cnt);
    //get the 'l' and 'r'
    memset(l, 0, sizeof(l)); memset(r, 0, sizeof(r));
    for (int i = 1; i <= cnt; ++i) {
        r[point[i].id] = i;
        if (!l[point[i].id])    l[point[i].id] = i;
    }
}

void solve() {
    ll Max;
    int j, id, idOfPoint;
    for (int len = 1; len <= cnt; ++len) {
        for (int i = 1; i + len - 1 <= cnt; ++i) {
            j = i + len - 1;

            dp[i][j] = 1ll<<60;
            //find the maximum value
            Max = -(1ll<<60);
            id = -1;
            for (int k = i; k <= j; ++k) {
                idOfPoint = point[k].id;
                if (l[idOfPoint] >= i && r[idOfPoint] <= j && cost[idOfPoint] > Max) {
                    Max = cost[idOfPoint];
                    id = idOfPoint;
                }
            }

            if (id == -1)   {//means that there is no entire segment in [i, j]
                dp[i][j] = 0;
                continue;
            }        

            //find the location to eject the beam
            for (int k = l[id]; k <= r[id]; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + Max);
            }
            // cout << i << ' ' << j << " now\n";
            // cout << dp[i][j] << endl;
        }
    }
}
int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        input();
        solve();
        printf("%lld\n", dp[1][cnt]);
        // for (int i = 1; i <= cnt; ++i)  cout << point[i].id << ' ';
        // cout << endl;

        // for (int i = 1; i <= 3; ++i) {
        //     cout << l[i] << ' ' << r[i] << endl;
        // }
    }
}