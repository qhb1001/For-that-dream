#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX = 1e5;
ll get(ll x) {
    return x * (x + 1) / 2;
}
int main() {
    ll sum; cin >> sum;
    bool flag = false;
    for (ll k = 1; k * (k + 1) / 2 < sum; ++k) {
        ll l = 1, r = MAX, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (get(mid) + get(k) >= sum) r = mid - 1;
            else l = mid + 1;
        }
        mid = l + r >> 1;
        for (int i = -3; i <= 3; ++i) if (mid + i >= 1 && get(k) + get(mid + i) == sum) {flag = true; break;}
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}