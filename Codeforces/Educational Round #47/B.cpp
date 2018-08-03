#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string in;
    string ans1 = "", ans2 = "";
    cin >> in;
    int len = in.size();
    for (int i = 0; i < len; ++i) {
        if (in[i] == '1')   ans1 += '1';
        else    ans2 += in[i];
    }

    int cnt = 0;
    len = ans2.size();
    for (int i = 0; i < len; ++i) {
        if (ans2[i] == '0') cnt += 1;
        else    break;
    }

    len = ans1.size();
    for (int i = 0; i < cnt; ++i)   cout << '0';
    for (int i = 0; i < len; ++i)   cout << '1';
    len = ans2.size();
    for (int i = cnt; i < len; ++i) cout << ans2[i];
    cout << endl;
}