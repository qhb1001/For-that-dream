#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const double EPS = 1e-9;
struct Point {
    double x, y;
    void in() {
        scanf("%lf%lf", &x, &y);
    }
};
double dis(Point a, Point b) {
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int cmp(double a, double b) {
    if (abs(a - b) <= EPS)  return 0;
    if (a - b <= EPS)   return -1;
    return 1;
}
double ans;
void deal(Point a, Point b, Point c, double w) {
    //以a b作为底边，c作为顶点
    double ba = dis(b, a), bc = dis(b, c), ac = dis(a, c);
    // cout << ba << ' ' << bc << ' ' << ac << endl;
    double angle = acos((ba*ba + bc*bc - ac*ac) / (2.0*ba*bc));
    double h = bc*sin(angle);

    // cout << h << endl;
    if (cmp(ba, w) <= 0) { 
        ans = min(ans, h);

    }

    //以a b作为侧边，c作为顶点
    if (cmp(w, h) >= 0) ans = min(ans, ba);
}
int main() {
    // freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    Point a, b, c;
    double w;
    while (T--) {
        a.in(); b.in(); c.in(); scanf("%lf", &w);
        ans = 1<<30;
        deal(a, b, c, w);
        deal(a, c, b, w);
        deal(b, c, a, w);
        if (cmp(ans, 1<<30) == 0)   printf("impossible\n");
        else    printf("%.10lf\n", ans);
    }
}