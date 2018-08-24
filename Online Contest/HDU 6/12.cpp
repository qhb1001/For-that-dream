#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double g = 9.8;
const double PI = acos(-1.0);
const double EPS = 1e-9;
struct Point {
    double x, y;
    void in() {
        scanf("%lf%lf", &x, &y);
    }
}slope, origin;
int main() {
    // freopen("input", "r", stdin);
    // freopen("output.a", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        double a, b, x, y;
        scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
        a *= -1;
        double angle = atan(b / -a);
        double ax = g * sin(angle), ay = g * cos(angle);
        double dy = y - b * x / a;
        double h = dy * cos(angle);
        double t = sqrt(2 * (-x / cos(angle) + dy * sin(angle)) / ax);
        int ans = 1;
        // double now = sqrt(2 * h / ay);
        // while (true) {
        //     now += 2 * sqrt(2 * ay * h) / ay;
        //     // cout << t << ' ' << now << endl;
        //     if (now > t) break;
        //     ++ans;
        // }

        double tim = sqrt(2 * h / ay);
        t -= tim;
        ans += (int)(t / (2 * tim));
        printf("%d\n", ans);
    }
}