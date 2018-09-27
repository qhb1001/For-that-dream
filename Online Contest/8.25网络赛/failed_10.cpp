#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int T, n, bit[MAX<<2], dp[MAX];
int lowbit(int k){
    return k&(-k);
}
void update(int pos,int num){
    while(pos<=n){
        bit[pos]=max(bit[pos],num);
        pos+=lowbit(pos);
    }
}
int query(int k){
    int anss=0;
    while(k>0){
        anss=max(anss,bit[k]);
        k-=lowbit(k);
    }
    return anss;
}
struct Point {
    int x, y, val;
    bool operator < (const Point b) const {
        if (y != b.y)   return y < b.y;
        return x < b.x;
    }
}p[MAX];
void init() {
    memset(bit, 0, sizeof(bit));
    memset(dp, 0, sizeof(dp));
}
int find(int x, int y) {
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (p[mid].y >= y)  r = mid - 1;
        else    l = mid + 1;
    }

    r = l + r >> 1;
    // for (int i = -5; i <= 5; ++i) if (r + i >= 1 && r + i <= n && p[i + r].y == y)  {r = i + r; break;}
    int R = r;
    while (l < r) {
        mid = l + r >> 1;
        if (p[mid].x >= x)  r = mid - 1;
        else    l = mid + 1;
    }
    int ans = l + r >> 1;
    return ans;
    // for (int i = 5; i >= -5; --i) if (ans + i >= 1 && ans + i < R && p[i + ans].x == x)  return ans + i;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].val);
        sort(p + 1, p + 1 + n);
        init();
        int i = 1;
        while (i <= n && p[i].y == 0)   ++i;
        while (i <= n && p[i].x == 0)   ++i;

        int ans = 0;

        for (; i <= n; ++i) { 
            int idx = find(p[i].x, p[i].y);
            dp[i] = query(idx - 1) + p[i].val;
            // cout << dp[i] << ' ' << idx << endl;
            update(i, dp[i]);
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
}