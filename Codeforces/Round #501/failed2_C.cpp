#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
struct Song {
    ll a, b;
}song[MAX];
ll m, n, lSum1[MAX], rSum1[MAX], lSum2[MAX], rSum2[MAX];
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> song[i].a >> song[i].b;
    }
    sort(song + 1, song + 1 + n, [](Song a, Song b) {
        return a.a > b.a;
    });
    
    for (int i = 1; i <= n; ++i) lSum1[i] = lSum1[i - 1] + song[i].b;//the sum of the b-value from the left
    for (int i = n; i >= 1; --i) rSum1[i] = rSum1[i + 1] + song[i].a;//the sum of the a-value from the right

    sort(song + 1, song + 1 + n, [](Song a, Song b) {
        return a.b < b.b;
    });

    for (int i = 1; i <= n; ++i) lSum2[i] = lSum2[i - 1] + song[i].b;
    for (int i = n; i >= 1; --i) rSum2[i] = rSum2[i + 1] + song[i].a;
}

int deal() {
    if (lSum1[n] > m)   return -1;

    for (int i = 0; i <= n; ++i) {
        if (lSum1[i] + rSum1[i + 1] <= m)   return i;
        if (lSum2[i] + rSum2[i + 1] <= m)   return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << deal() << endl;
}