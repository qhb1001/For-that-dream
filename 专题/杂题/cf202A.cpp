#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 11;
bool check(string a, int len) {
    int cnt = len - 1;
    for (int i = 0; i < len; ++i) if (a[i] != a[cnt--]) return false;
    return true;
}
int main() {
    string a, ans = "a"; cin >> a;
    
    int len = a.size();
    for (int i = 1; i < (1<<len); ++i) {
        string b; 
        int x = i, cnt = 0;
        while (x) {
            if (x & 1) b += a[cnt];
            x >>= 1;
            ++cnt; 
        }
        if (check(b, b.size()))  ans = max(ans, b);
    }
    cout << ans << endl;
}
