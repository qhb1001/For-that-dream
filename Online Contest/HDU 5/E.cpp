#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
const double PI = acos(-1.0);
const int MAX = 105;
const double EPS = 1e-5;
struct Point {
    double x, y;
    Point(double a = 0, double b = 0) {
        x = a;
        y = b;
    }
};
struct Cycle {
    Point centre;
    double r;
}cycle[MAX];
double dis(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int cmp(double a, double b) {
    if (a - b >= EPS)    return 1;
    else if (b - a >= EPS)   return -1;
    return 0;
}
bool check(Cycle a) {//判断是否相交
    double d = dis(a.centre, cycle[0].centre);
    if (cmp(d, cycle[0].r - a.r) >= 0 && cmp(cycle[0].r + a.r, d) >= 0) return true;
    return false;
}
int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        cycle[0].centre = Point(0, 0);
        int m;
        scanf("%d%lf", &m, &cycle[0].r);

        for (int i = 1; i <= m; ++i) {
            scanf("%lf%lf%lf", &cycle[i].centre.x, &cycle[i].centre.y, &cycle[i].r);
        }

        double angle, d, r, R = cycle[0].r, ans = 2 * PI * R, beta;
        // cout << ans << endl;
        for (int i = 1; i <= m; ++i) {
            if (check(cycle[i])) {
                // cout << i << endl;
                d = dis(cycle[0].centre, cycle[i].centre);
                r = cycle[i].r;
                beta = acos((R * R + d * d - r * r) / (2 * R * d));
                angle = acos((d * d + r * r - R * R) / (2 * d * r));
                ans += 2 * angle * r - 2 * beta * R;
            }
        }

        printf("%.7lf\n", ans);
    }
}