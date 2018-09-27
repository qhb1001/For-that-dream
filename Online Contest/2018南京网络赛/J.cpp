#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX = 2e7 + 5;
typedef long long ll;
bool vis[MAX];
bool check(ll x) {
    ll t = sqrt(x);
    if (t*t == x)   return true;
    return false;
}
int main() {
    for (int i = 4; i <= MAX; ++i) {
        if (vis[i] || check(i)) {
            for (int j = 1; j * i <= MAX; ++j) {
                vis[j * i] = 1;
            }
        }
    }

    int num = 0;
    for (int i = 1; i < MAX; ++i)   if (!vis[i])    ++num;
    cout << num << endl;
}