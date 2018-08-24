#include <iostream>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll m, n, res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (n--) {
        ll now;
        cin >> now;
        now += res;

        if (now % m == 0)   {
            cout << now / m << ' ';
            res = 0;
        } else {
            cout << now / m << ' ';
            res = now % m;
        }
    }
}