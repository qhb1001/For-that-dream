#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int len;
    string in;
    cin >> len >>  in;
    if (len == 1)   {
        cout << "Yes\n";
        return 0;
    }
    int letter[30] = {0};
    for (int i = 0; i < len; ++i)   {
        letter[in[i] - 'a']++;
    }
    for (int i = 0; i < 30; ++i)    if (letter[i] >= 2) {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}