#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 2e5 + 5;
int aaa[MAX], n, s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> aaa[i];
    sort(aaa + 1, aaa + 1 + n);

    int mid = (n + 1) / 2;
    if (aaa[mid] == s) cout << 0 << endl;
    else if (aaa[mid] > s) {
        long long ans = 0;
        ans += aaa[mid] - s;
        mid--;
        while (mid >= 1 && aaa[mid] > s)  ans += aaa[mid--] - s;
        cout << ans << endl;
    } else {
        long long ans = 0;
        ans += s - aaa[mid];
        mid++;
        while (mid <= n && aaa[mid] < s)  ans += s - aaa[mid++];
        cout << ans << endl;
    }
}