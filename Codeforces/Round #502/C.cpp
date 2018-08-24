#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n%2 == 1) {
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        for (int i = n / 2 + 1; i <= n; ++i) {
            cout << i << ' ';
        }
        for (int i = 1; i <= n / 2; ++i) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}