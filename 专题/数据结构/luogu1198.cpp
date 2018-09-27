#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 2e5 + 5;
typedef long long ll;
const ll INF = -(1LL<<60);
struct Node {
    int l, r;
    ll val;
}t[MAX<<3];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].val = INF;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
}
void update(int i, int id, ll val) {
    if (t[i].l == t[i].r) {
        t[i].val = val;
        return ;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (id <= mid)  update(i<<1, id, val);
    else    update(i<<1|1, id, val);
    t[i].val = max(t[i<<1].val, t[i<<1|1].val);
}
ll query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r) return t[i].val;
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(i<<1, l, r);
    else if (l > mid)   return query(i<<1|1, l, r);
    else return max(query(i<<1, l, mid), query(i<<1|1, mid + 1, r));
}
int main() { 
    build(1, 1, MAX);
    int cnt = 0, q;
    ll last = 0, mod, val;
    scanf("%d%lld", &q, &mod);
    char s[2];
    while (q--) {
        scanf("%s%lld", s, &val);
        if (s[0] == 'A') update(1, ++cnt, (last + val) % mod);
        else {
            last = query(1, cnt - val + 1, cnt);
            printf("%lld\n", last);
        }
    }
}