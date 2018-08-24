#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 105;
int a[MAX], x, n, ans;
void deal() {
    int Max = 0, idx;
    for (int i = 1; i <= n; ++i)    if (Max < a[i]) {Max = a[i]; idx = i;}
    if (Max == x)   return ;
    int left = 0, right = 0;
    for (int i = 1; i < idx; ++i)   left += a[i];
    for (int i = idx + 1; i <= n; ++i)  right += a[i];
    int dx1 = (idx - 1) * x - left, dx2 = (n - idx) * x - right, dx3 = Max - x;
    if (dx1 > 0) {
        if (dx1 >= dx3) {
            a[idx - 1] += dx3;
            a[idx] -= dx3;
            ++ans;
            return ;
        } else {
            a[idx - 1] += dx1;
            a[idx] -= dx1;
            dx3 -= dx1;
            ++ans;
        }
    }

    if (dx2 > 0) {
        if (dx2 >= dx3) {
            a[idx + 1] += dx3;
            a[idx] -= dx3;
            ++ans;
            return ;
        } else {
            a[idx + 1] += dx2;
            a[idx] -= dx2;
            ++ans;
        }
    }
}

void deal2() {
    int Min = 1<<30, idx;
    for (int i = 1; i <= n; ++i) if (Min > a[i]) {Min = a[i]; idx = i;}
    if (Min == x)   return ;
    int left = 0, right = 0;
    for (int i = 1; i < idx; ++i)   left += a[i];
    for (int i = idx + 1; i <= n; ++i)  right += a[i];
    int dx1 = left - (idx - 1) * x, dx2 = right - (n - idx) * x, dx3 = Min - x;

    if (dx1 > 0) {
        if (dx1 >= dx3) {
            int t = min(dx3, a[idx - 1]);
            a[idx - 1] -= t;
            a[idx] += t;
            return ;
        } else {
            int t = min(dx1, a[idx - 1]);
            a[idx - 1] -= t;
            a[idx] += t;
            dx3 -= t;
        }
    }

    if (dx2 > 0) {
        if (dx2 >= dx3) {
            int t = min(dx3, a[idx + 1]);
            a[idx + 1] -= t;
            a[idx] += t;
            return ;
        } else {
            int t = min(dx2, a[idx + 1]);
            a[idx + 1] -= t;
            a[idx] += t;
        }
    }
}
bool check() {
    for (int i = 1; i <= n; ++i)    if (a[i] != x)  return false;
    return true;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        x += a[i];
    }
    x /= n;
    while (!check())    {
        for (int i = 1; i <= n; ++i)    cout << a[i] << ' ';
        cout << ans << endl;
        deal();
        deal2();
    }
    cout << ans << endl;
    
}