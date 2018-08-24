#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, h, a, b, q;
    cin >> n >> h >> a >> b >> q;
    ll x1, y1, x2, y2;
    while (q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)   cout << abs(y1 - y2) << endl;
        else {
            if (a <= y1 && y1 <= b) {
                cout << abs(x1 - x2) + abs(y1 - y2) << endl;
            } else {
                if (abs(y1 - a) < abs(y1 - b)) {
                    cout << abs(a - y1) + abs(x1 - x2) + abs(a - y2) << endl;
                } else {
                    cout << abs(b - y1) + abs(x1 - x2) + abs(b - y2) << endl;
                }
            }
        }
    }
}