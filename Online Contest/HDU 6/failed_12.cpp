#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double EPS = 1e-4;
const double g = 9.8;
const double PI = acos(-1.0);
struct Point {
    double x, y;
    void in() {
        scanf("%lf%lf", &x, &y);
    }
 }origin, slope;
 struct State {
     double vx, vy;
     Point now;
 }temp;

State binary() {
    double l = 0, r = 1000, mid;
    Point t;
    while (r - l >= EPS) {
        mid = (l + r) / 2;
        t.y = temp.now.y + temp.vy * mid - g * mid * mid / 2;
        t.x = temp.vx * mid + temp.now.x;
        if (origin.y * t.x / origin.x - t.y <= 0)   l = mid;
        else    r = mid;
    }

    State tt;
    mid = (l + r) / 2;
    tt.now.y = temp.now.y + temp.vy * mid - g * mid * mid / 2;
    tt.now.x = temp.vx * mid + temp.now.x;
    tt.vx = temp.vx;
    tt.vy = -temp.vy + g * mid;
    return tt;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        slope.in(); origin.in();
        int ans = 0;
        slope.x *= -1;
        State now;
        now.vy = sqrt(2 * g * (origin.y - origin.x * slope.y / slope.x));
        now.vx = 0;
        now.now.x = origin.x; 
        now.now.y = origin.x * slope.y / slope.x;
        while (true) {
            double angle1;
            if (now.vx == 0) {
                angle1 = PI / 2;
            } else {
                angle1 = atan(now.vy / now.vx);
            }
            double angle2 = atan(slope.y / -slope.x);
            double angle3 = angle1 - angle2;
            double angle4 = angle2 - angle3;
            double v = sqrt(now.vx * now.vx + now.vy * now.vy);
            
            temp.vx = v * cos(angle4);
            temp.vy = sqrt(v * v - temp.vx * temp.vx);
            temp.now = now.now;
            now = binary();
            // cout << now.now.x << ' ' << now.now.y << endl;
            if (now.now.x <= 0) ++ans;
            else    break;
        }

        printf("%d\n", ans + 1);
    }
}