#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5e5 + 5;
int n, a[MAX];
bool cmp(int a, int b) {
    return a > b;
}
void deal(int l, int r) {
    int now = 1;
    if (r == l) return ;
    while ((1<<(now+1)) <= r + 1) ++now;
    int len = r - ((1<<now) - 1);
    
    if (len != 0)   sort(a + r - 2 * len + 1, a + r + 1, cmp);
    sort(a + len, a + r - 2 * len + 1, cmp);
    if (len == 0)   return ;
    deal(0, len - 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) a[i] = i;
    deal(0, n - 1);
    for (int i = 0; i < n - 1; ++i) printf("%d ", a[i]);
    printf("%d\n", a[n - 1]);
    return 0;
}

