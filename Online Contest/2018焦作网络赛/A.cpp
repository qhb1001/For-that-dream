#include <string>
#include <iostream>
#include <map>
using namespace std;
map<char, char> mp;
int main() {
    for (char c = 'a'; c <= 'z'; ++c)   mp[c] = c;
    for (char c = 'A'; c <= 'Z'; ++c)   mp[c] = c +32;
    int T; cin >> T;
    string a;
    while (T--) {
        cin >> a;
        int len = a.size();
        for (int i = 0; i < len; ++i) a[i] = mp[a[i]];
        if (a == "jessie") cout << "Good guy!\n";
        else cout << "Dare you say that again?\n";
    }
}