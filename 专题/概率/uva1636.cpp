#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    string a;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> a) {
        int cnt1 = a.size(), cnt2 = 0, cnt3 = 0, ans;
        for (int i = 0; i < cnt1; ++i) {
            if (a[i] == '0')    ++cnt2;
            if (a[i] == '0' && a[(i + 1) % cnt1] == '0')    ++cnt3;
        }
        ans = (cnt1*cnt3 - cnt2*cnt2);
        if (ans == 0)   cout << "EQUAL\n";
        else if (ans > 0)   cout << "SHOOT\n";
        else    cout << "ROTATE\n";
    }
}