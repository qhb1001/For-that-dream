#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e7 + 5;
typedef long long ll;
ll f[MAX];
bool flag[MAX];
int a[MAX];
void prime() {
    flag[0] = 1; flag[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        if (!flag[i]) {
            for (int j = i; j < MAX; j += i) {
                if (a[j]) f[i] += a[j];
                flag[j] = 1;
            }
        }
    }
}
int main() {
    int n; scanf("%d", &n);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x); ++a[x];
    }
    prime();
    int q, l, r;
    scanf("%d", &q);
    for (int i = 1; i < MAX; ++i) f[i] += f[i - 1];
    while (q--) {
        scanf("%d%d", &l, &r);
        l = min(l, MAX - 5);
        r = min(r, MAX - 5);
        printf("%lld\n", f[r] - f[l - 1]);
    }
}