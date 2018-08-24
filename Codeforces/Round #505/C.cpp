#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string in;
int len, ans = 1;
int check(string a) {
    bool flag = true;
    int now = 1, idx = -1;
    // cout << a << endl;
    for (int i = len - 2; i >= 0; --i) {
        if (a[i] != a[i + 1])   ++now;
        else {
            ans = max(now, ans);
            now = 1;
            idx = i;
        }
    }

    // cout << idx << endl;
    ans = max(now, ans);
    return idx;
}
string reverse(string a, int idx) {
    string ans = "";
    for (int i = idx; i >= 0; --i)  ans += a[i];
    for (int i = len - 1; i > idx; --i) ans += a[i];
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> in;
    len = in.size();
    while (true) {
        int idx = check(in);
        if (in[0] == in[len - 1])   break;
        if (idx == -1)  break;
        in = reverse(in, idx);
    }
    cout << ans << '\n';
}