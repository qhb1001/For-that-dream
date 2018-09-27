#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define P pair<ll, ll>
const ll MAX = 2e9;
const int MAXN = 2e5 + 5;
ll n, m, k, s, x;
P a[MAXN], b[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k >> x >> s;
    for (int i = 1; i <= m; ++i) cin >> a[i].second;
    for (int i = 1; i <= m; ++i) cin >> a[i].first;
    int len = 1;
    for (int i = 1; i <= k; ++i) cin >> b[i].second;
    for (int i = 1; i <= k; ++i) cin >> b[i].first;

    for (int i = 2; i <= k; ++i) {
        if (b[i].first == b[i - 1].first && b[i].second >= b[i - 1].second) b[len] = b[i];
        else b[++len] = b[i];
    }

    a[++m].first = 1LL<<50;
    ll ans = n * x, xx;
    for (int i = 1; i <= m; ++i) {
        ll now = s, sum = 0;
        xx = x;
        if (now >= a[i].first) {now -= a[i].first; xx = a[i].second;}

        int l = 1, r = len + 1, mid, ans_ = -1;
        while (l < r) {
            mid = l + r >> 1;
            if (b[mid].first <= now) l = mid + 1;
            else r = mid - 1;
        }

        mid = l + r >> 1;
        for (int i = 5; i >= -5; --i) if (mid + i >= 1 && mid + i <= len && b[mid + i].first <= now) {ans_ = mid + i; break;}
        if (ans_ != -1) sum += (n - b[ans_].second) * xx;
        else sum += n * xx;
        
        ans = min(ans, sum);
    }

        
    cout << ans << endl;
} 