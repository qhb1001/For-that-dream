#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string a, b;
int len;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >>  len >> a >> b;
    int ans = 0;
    for (int i = 0; i < len - 1; ++i) {
        if (a[i] != a[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]) {swap(a[i], a[i + 1]); ++ans; ++i;}
    }

    for (int i = 0; i < len; ++i) if (a[i] != b[i]) ++ans;
    cout << ans << endl;
}