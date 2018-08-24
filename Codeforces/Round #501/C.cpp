#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
struct Song {
    ll a, b, val;
}song[MAX];
ll m, n, sum;
void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> song[i].a >> song[i].b;
        song[i].val = song[i].a - song[i].b;
        sum += song[i].a;
    }
    
    sort(song + 1, song + 1 + n, [](Song a, Song b) {
        return a.a - a.b > b.a - b.b;
    });    
}

int deal() {
    if (sum <= m)   return 0;
    for (int i = 1; i <= n; ++i) {
        sum -= song[i].val;
        if (sum <= m)   return i;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    cout << deal() << endl;
}