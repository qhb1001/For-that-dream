#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;
int gcd(int a, int b) {
    return b == 0? a: gcd(b, a%b);
}
int p[1000], pr[1000], tot;
void init() {
    p[1]=1;
    tot = 0;
    for (int i = 2; i <= 100; ++i) { // 其中N代表最大值
        if (!p[i]) p[i]=i,pr[++tot]=i;
        for (int j=1;j<=tot&&pr[j]*i<=100;j++) {
            p[i*pr[j]]=pr[j];
            if (p[i]==pr[j]) break;
        }
    }
}
int main() {
    int last, ans;
    init();
    for (int n = 1; n <= 100; ++n) {
        last = ans;
        ans = 0;
        int cnt = 0;
        for (int i = 1; i <= tot && pr[i] <= n; ++i) ++cnt;
        int ans_ = (cnt*(cnt-1)) / 2;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                // cout << gcd(i + j, i - j) << endl;
                if (gcd(i + j, i - j) == 1) ++ans;
            }
        }
        cout << ans <<  ' ' << ans - last << ' ' << ans_ << ' ' << ans - ans_ << endl;
    }
}