#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int a[MAX], st[MAX][18], n, q;
void input() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        st[i][0] = a[i];
    }
    for (int k = 1; (1<<k) <= n; ++k) {
        for (int i = 1; i + (1<<k) - 1 <= n; ++i) {
            st[i][k] = max(st[i][k - 1], st[i + (1<<(k - 1))][k - 1]);
        }
    }
}
int RMQ(int l, int r) {
    int k = 0;
    while ((1<<(k + 1)) <= r - l + 1)   ++k;
    return max(st[l][k], st[r - (1<<k) + 1][k]);
}
int main() {
    input();
    int l, r;
    while (q--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", RMQ(l, r));
    }
}