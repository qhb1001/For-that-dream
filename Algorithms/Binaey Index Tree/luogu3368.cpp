#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 5e5 + 5;
typedef long long ll;
ll C[MAX];
int n;
inline int lowbit(int x) {return x & -x;}
void add(int i, ll x) {
    for (; i <= n; i += lowbit(i)) C[i] += x;
}
ll query(int i) {
    ll ans = 0;
    for (; i; i -= lowbit(i)) ans += C[i];
    return ans;
}
int main() { 
    int m, type, x, y;
    ll k, last = 0, now;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)    {scanf("%lld", &now); add(i, now - last); last = now; }
    while (m--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%lld", &x, &y, &k);
            add(y + 1, -k);
            add(x, k);
        } else {
            scanf("%d", &x);
            printf("%lld\n", query(x));
        }
    }

}