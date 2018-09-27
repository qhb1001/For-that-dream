#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 5e5 + 5;
int C[MAX<<5], n;
inline int lowbit(int x) {return x&-x;}
void add(int i, int x) {
    for (; i <= n; i += lowbit(i)) C[i] += x;
}
int sum(int i) {
    int ans = 0;
    for (; i; i -= lowbit(i)) ans += C[i];
    return ans;
}
int main() {
    int type, l, r, t, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {scanf("%d", &t); add(i, t);}
    while (m--) {
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1)  add(l, r);
        else printf("%d\n", sum(r) - sum(l - 1));
    }
}