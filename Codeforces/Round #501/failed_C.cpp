#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
struct Node {
    ll a, b;
    bool operator < (const Node b) const {
        return a < b.a;
    }
}song[MAX];

ll n, m;
ll l_sum[MAX], r_sum[MAX];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> song[i].a >> song[i].b;
    }
    sort(song + 1, song + 1 + n);

    for (int i = 1; i <= n; ++i)    l_sum[i] = l_sum[i - 1] + song[i].a;
    for (int i = n; i >= 1; --i)    r_sum[i] = r_sum[i + 1] + song[i].b;
}

int binarySearch() {
    if (r_sum[1] > m)   return -1;
    if (l_sum[n] <= m)  return 0;
    int l = 0, r = n + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (l_sum[mid] + r_sum[mid + 1] <= m)   l = mid + 1;
        else    r = mid - 1;    
    }

    int ans = (l + r) >> 1;
    for (int i = 5; i >= -5; --i) {
        if (ans + i <= n && l_sum[ans + i] + r_sum[ans + i + 1] <= m)   return ans + i;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    // cout << binarySearch() << endl;

    if (r_sum[1] > m)   {
        cout << -1;
        return 0;
    }

    if (r_sum[2] > m && r_sum[1] <= m) {
        cout << n << endl;
        return 0;
    }
    for (int i = n; i >= 0; --i) {
        if (l_sum[i] + r_sum[i + 1] <= m)   {
            cout << n - i << endl;
            return 0;
        }
    }
}