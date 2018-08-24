#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
string s;
int len, q;
int pre[30][MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        cin >> len >> q >> s;
        memset(pre, 0, sizeof(pre));
        for (char c = 'A'; c != 'Z' + 1; ++c) {
            for (int i = 0; i < len; ++i) {
                pre[c - 'A'][i + 1] = pre[c - 'A'][i];
                if (s[i] == c)  pre[c - 'A'][i + 1]++;
            }
        }
        cout << "Case #" << kase << ":\n";
        int l, r;
        while (q--) {
            cin >> l >> r;
            for (char c = 'A'; c != 'Z' + 1; ++c) {
                if (pre[c - 'A'][r] - pre[c - 'A'][l - 1] != 0) {
                    cout << pre[c - 'A'][r] - pre[c - 'A'][l - 1] << '\n';
                    break;
                }
            }
        }
    }
}