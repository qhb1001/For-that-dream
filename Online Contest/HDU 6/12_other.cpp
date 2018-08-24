#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const double g = 9.8;
double a, b, x, y, vx, vy;
void solve()
{
    scanf("%lf%lf%lf%lf", &a, &b, &x, &y);
    vx = vy = 0;
    int ans = 0;
    double dir = atan2(-b, a);
    while(1)
    {
        double aa = a * g / 2;
        double bb = -a * vy - b * vx;
        double cc = -a * y - b * x;
        double delta = bb * bb - 4 * aa * cc;
        if(delta < 0)
            delta = 0;
        double t = (-bb + sqrt(delta)) / (2 * aa);
        x += vx * t;
        y += vy * t - g * t * t / 2;
        if(x > 0)
            break;
        ans++;
        vy -= g * t;
        double nowdir = atan2(vy, vx);
        double len = sqrt(vx * vx + vy * vy);
        nowdir = dir * 2 - nowdir;
        vx = len * cos(nowdir);
        vy = len * sin(nowdir);
//        printf("x=%f, y=%f, vx=%f, vy=%f\n", x, y, vx, vy);
//        system("pause");
    }
    printf("%d\n", ans);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.b", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int t1 = 1; t1 <= T; t1++)
        solve();
    return 0;
}