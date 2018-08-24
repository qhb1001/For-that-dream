#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string s, t;
int lenS, lenT, ok[1005];
void deal() {
    for (int i = 0; i + lenT <= lenS; ++i) {
        bool flag = true;
        for (int j = 0; j < lenT; ++j) {
            if (s[i + j] != t[j])   {
                flag = false;
                break;
            }
        }
        if (flag)   ok[i] = 1;
    }
}

int get(int l, int r) {
    int ans = 0;
    for (int i = 0; i + l + lenT - 1 <= r; ++i) {
        ans += ok[i + l];
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, l, r;
    cin >> n >> m >> q;
    cin >> s >> t;
    lenS = s.size();
    lenT = t.size();
    deal();
    while (q--) {
        cin >> l >> r;
        cout << get(l - 1, r - 1) << '\n';
    }
}