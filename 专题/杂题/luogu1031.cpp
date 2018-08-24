#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 105;
int a[MAX], x, ans, n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        x += a[i];
    }
    x /= n;

    for (int i = 1; i <= n; ++i)    a[i] -= x;
    for (int i = 1; i < n; ++i) if (a[i] != 0) {
        a[i + 1] += a[i];
        ++ans;
    }

    cout << ans << endl;
}