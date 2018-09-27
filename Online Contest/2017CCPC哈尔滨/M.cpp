#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <time.h>
#define P pair<double, double>
using namespace std;
const int MAX = 1e5 + 5;
const double EPS = 1e-6;
P p[MAX];
int cmp(double a, double b) {
    if (a - b > EPS) return 1;
    if (b - a > EPS)    return -1;
    return 0;
}
P get(P aa, P bb, P cc) {
    P A(0, 0), B, C, ans;
    if (cmp(aa.first, bb.first) == 0) {A = aa; B = bb; C = cc;}
    if (cmp(aa.first, cc.first) == 0) {A = aa; B = cc; C = bb;}
    if (cmp(bb.first, cc.first) == 0) {A = bb; B = cc; C = aa;}
    if (A != P(0, 0)) {
        if (A.second == C.second) swap(A, B);
        ans.second = (A.second + B.second) / 2;
        double k = (A.second - C.second) / (A.first - C.first);
        double midx = (A.first + C.first) / 2;
        double midy = (A.second + C.second) / 2;
        ans.first = -k * (ans.second - midy) + midx;
        return ans;
    }   
    if (cmp(aa.second, bb.second) == 0) {A = aa; B = bb; C = cc;}
    if (cmp(aa.second, cc.second) == 0) {A = aa; B = cc; C = bb;}
    if (cmp(bb.second, cc.second) == 0) {A = bb; B = cc; C = aa;}
    if (A != P(0, 0)) {
        ans.first = (A.first + B.first) / 2;
        double k = (A.second - C.second) / (A.first - C.first);
        double midx = (A.first + C.first) / 2;
        double midy = (A.second + C.second) / 2;
        ans.second = -(ans.first - midx) / k + midy;
        return ans;
    }

    double a = (bb.first - aa.first) / (aa.second - bb.second);
    double b = (aa.first + bb.first) / 2;
    double c = (aa.second + bb.second) / 2;
    double d = (bb.first - cc.first) / (cc.second - bb.second);
    double e = (cc.first + bb.first) / 2;
    double f = (cc.second + bb.second) / 2;
    ans.first = (f - c - d * e + a * b) / (a - d);
    ans.second = a * (ans.first - b) + c;
    return ans;
}
double dis(P a, P b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}
int main() {
    // freopen("input.txt", "r", stdin);
    srand((unsigned)time(NULL));
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; ++i)  scanf("%lf%lf", &p[i].first, &p[i].second);

        if (n == 1) {
            printf("%lf %lf %lf\n", p[1].first + 1, p[1].second, dis(P(p[1].first + 1, p[1].second), p[1]));
            continue;
        } else if (n == 2 || n == 3 || n == 4) {
            P now((p[1].first + p[2].first) / 2, (p[1].second + p[2].second) / 2);
            printf("%lf %lf %lf\n", now.first, now.second, dis(now, p[1]));
            continue;
        } 

        int a, b, c, num, want = ceil(n / 2.0);
        P now;
        double r;

        // cout << get(p[1], p[2], p[3]).first << ' ' << get(p[1], p[2], p[3]).second << endl;
        while (true) {
            a = rand() % n + 1;
            b = rand() % n + 1;
            c = rand() % n + 1;
            while (a == b) b = rand() % n + 1;
            while (c == a || c == b) c = rand() % n + 1;

            // cout << a << ' ' << b << ' ' << c << endl;
            if ((p[b].second - p[a].second) * (p[c].first - p[a].first) == 
            (p[c].second - p[a].second) * (p[b].first - p[a].first)) continue;


            now = get(p[a], p[b], p[c]);
            r = dis(now, p[a]);
            num = 0;
            for (int i = 1; i <= n; ++i) {
                if (cmp(dis(now, p[i]), r) == 0) ++num;
                if (num >= want) break;
                if (num + n - i < want) break;
            }
            if (num >= want) break;
        }

        printf("%.4lf %.4lf %.4lf\n", now.first, now.second, r);
    }
}