#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 3000;
string in;
int n, len;
bool check(string a) {
    int len = a.size();
    for (int i = 0; i < len; ++i)   if (a[i] == 'E')    return false;
    return true;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        string t;
        cin >> t;
        in = in + t;
        if (!check(t))   break;
    }
    
    len = in.size();
    for (int i = 0; i < len; ++i)   if (in[i] == 'E') {len = i; break;}

    int l = 0, r = 0;
    for (int i = 0; i < len; ++i) {
        if (in[i] == 'W') ++l;
        else ++r;

        if (l >= 11 && l - r >= 2) {
            cout << l << ':' << r << '\n';
            l = r = 0;
        }
        if (r >= 11 && r - l >= 2) {
            cout << l << ':' << r << '\n';
            l = r = 0;
        }
    }
    cout << l << ':' << r << '\n';
    cout << '\n';

    l = r= 0;
    for (int i = 0; i < len; ++i) {
        if (in[i] == 'W') ++l;
        else ++r;

        if (l >= 21 && l - r >= 2) {
            cout << l << ':' << r << '\n';
            l = r = 0;
        }
        if (r >= 21 && r - l >= 2) {
            cout << l << ':' << r << '\n';
            l = r = 0;
        }
    }
    cout << l << ':' << r << '\n';
}