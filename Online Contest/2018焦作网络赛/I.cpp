#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 105;
int A, B, C;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while (cin >> A >> B >> C) {
        if (C % 2 == 0) cout << "Yes\n";
        else {
            if (A % 2 == 0 || B % 2 == 0) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}