#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
const int MAX = 2e4 + 5;
const int MAXX = 2e5 + 5;
char t[MAXX], now[14], c, in[MAXX];
string message, final_, temp, ans;
int L[MAXX], R[MAXX], len, node, id;
void build(int i, int cnt) {
    if (cnt == len) {t[i] = c; return ;}
    else if (now[cnt] == '0') {
        if (!L[i]) L[i] = ++node;
        build(L[i], cnt + 1);
    } else {
        if (!R[i])  R[i] = ++node;
        build(R[i], cnt + 1);
    }
}
bool query(int i) {
    if (id >= len) return false;
    if (t[i] != 0) {ans += t[i]; return true;}
    ++id;
    if (final_[id] == '0')  return query(L[i]);
    return query(R[i]);
}
map<char, string>mp;
int main() {
    mp['0'] = "0000"; mp['1'] = "0001"; mp['2'] = "0010"; mp['3'] = "0011"; mp['4'] = "0100"; mp['5'] = "0101"; mp['6'] = "0110"; mp['7'] = "0111";
    mp['8'] = "1000"; mp['9'] = "1001"; mp['A'] = "1010"; mp['B'] = "1011"; mp['C'] = "1100"; mp['D'] = "1101"; mp['E'] = "1110"; mp['F'] = "1111";
    mp['a'] = "1010"; mp['b'] = "1011"; mp['c'] = "1100"; mp['d'] = "1101"; mp['e'] = "1110"; mp['f'] = "1111";
    int T; scanf("%d", &T);
    while (T--) {
        memset(t, 0, sizeof(t));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
        int m, n; scanf("%d%d", &m, &n);
        node = 1;
        for (int i = 1, tt; i <= n; ++i) {
            scanf("%d%s", &tt, now);
            c = tt;
            len = strlen(now);
            build(1, 0);
        }
        message = "";
        scanf("%s", in);
        len = strlen(in);
        for (int i = 0; i < len; ++i) message += mp[in[i]];
        
        // cout << endl << message << endl;
        len *= 4;
        int idx = 0, cnt;
        final_ = "";
        // cout << len << endl; 
        while (true) {
            if (len - idx < 9)  break;
            cnt = 0;
            temp = "";
            for (int i = 0; i < 8; ++i)  {temp += message[i + idx]; if (message[i + idx] == '1') ++cnt;}
            if (cnt % 2 == 0 && message[idx + 8] == '1') final_ += temp;
            if (cnt % 2 == 1 && message[idx + 8] == '0') final_ += temp;
            // cout << endl << temp << ' ' << message[idx + 8] << ' ' << idx + 8 << endl;
            idx += 9;
        }
        
        len = final_.size();
        // cout << endl << final_ << endl;
        ans = ""; id = -1;
        while (true)    {if (query(1) == 0) break;}
        for (int i = 0; i < min(m, (int)ans.size()); ++i) printf("%c", ans[i]);
        puts("");
    }
}

