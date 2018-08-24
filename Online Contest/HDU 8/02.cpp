#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-6;
struct Point {
    double x, y; 
    Point(double a = 0, double b = 0): x(a), y(b) {}
    double dis(Point b) {
        double dx = x - b.x, dy = y - b.y;
        return sqrt(dx*dx + dy*dy);
    }
};
Point symmeric_point(Point p1, Point l1, Point l2) {
    Point ret;
    if (l1.x > l2.x - eps && l1.x < l2.x + eps) {
        ret.x = (2*l1.x - p1.x);
        ret.y = p1.y;
    } else {
        double k = (l1.y - l2.y) / (l1.x - l2.x);
        ret.x = (2*k*k*l1.x + 2*k*p1.y - 2*k*l1.y - k*k*p1.x + p1.x) / (1 + k*k);
        ret.y = p1.y - (ret.x - p1.x) / k;
    }
    return ret;
}
int main() {
    int T;
}