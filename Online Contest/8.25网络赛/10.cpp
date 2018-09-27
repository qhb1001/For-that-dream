#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int N, n, C[MAX<<2], dp[MAX];
struct Point {
    int x, y, val;
}p[MAX];
bool cmp1(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    else    return a.y < b.y;
}
bool cmp2(Point a, Point b) {
    if (a.y != b.y) return a.y < b.y;
    else    return a.x < b.x;
}
void discrete() { 
    sort(p + 1, p + 1 + n, cmp1);
    int cnt = 0, last;
    last = p[1].x;
    p[1].x = ++cnt;
    for (int i = 2; i <= n; ++i) {
        if (p[i].x == last) p[i].x = cnt;
        else {
            last = p[i].x;
            p[i].x = ++cnt;
        }
    }

    N = n;
    sort(p + 1, p + 1 + n, cmp2);
}
inline int lowbit(int x) {
    return x&(-x);
}
int query(int x) {
    int ans = 0;
    while (x > 0) {
        ans = max(ans, C[x]);
        x -= lowbit(x);
    }
    return ans;
}
void update(int x, int d) {
    while (x <= N) {
        C[x] = max(C[x], d);
        x += lowbit(x);
    } 
}

int main() {
    int T;
    scanf("%d", &T);
    p[0].y = -1;
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)    scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].val);
        discrete();
        memset(C, 0, sizeof(C));
        memset(dp, 0, sizeof(dp));
        int r = 1, l;
        bool flag = false;
        while (true) {
            l = r++;
            while (r <= n && p[r].y == p[l].y) ++r;
            if (r == n + 1) flag = true;

            int Max = 0;
            for (int i = l; i < r; ++i) {
                dp[i] = query(p[i].x - 1) + p[i].val;
                dp[i] = max(dp[i], query(p[i].x));
                dp[i] = max(dp[i], Max);
                Max = max(Max, dp[i]);
            }
            for (int i = l; i < r; ++i) update(p[i].x, dp[i]);
            if (flag)   break;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)    ans = max(ans, dp[i]);
        printf("%d\n", ans);
    }
}