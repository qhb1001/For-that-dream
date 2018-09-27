#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
int n, q, a[MAX];
ll pre[MAX];
struct Node{
    int l, r;
    ll sum, lazy;
}t[MAX<<6];

void up(int i) {
    t[i].sum = t[i<<1].sum + t[i<<1|1].sum;
}
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].lazy = 0;
    if (l == r) {t[i].sum = pre[l]; return ;}
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    up(i);
}
void push(int i) {
    if (t[i].lazy) {
        int len = t[i<<1].r - t[i<<1].l + 1;
        t[i<<1].sum += t[i].lazy * len;
        t[i<<1].lazy += t[i].lazy;

        len = t[i<<1|1].r - t[i<<1|1].l + 1;
        t[i<<1|1].sum += t[i].lazy * len;
        t[i<<1|1].lazy += t[i].lazy;
        t[i].lazy = 0;
    }
}
ll query(int i, int l, int r) {
    if (l > r) return 0;
    if (t[i].l == l && t[i].r == r) return t[i].sum;
    push(i);

    int mid = t[i].l + t[i].r >> 1;
    ll ans = 0;
    if (r <= mid)   ans =  query(i<<1, l, r);
    else if (l > mid)   ans =  query(i<<1|1, l, r);
    else ans = query(i<<1, l, mid) + query(i<<1|1, mid + 1, r);
    up(i);
    return ans;
}
void update(int i, int l, int r, ll val) {
    if (t[i].l == l && t[i].r == r) {
        t[i].sum += (r - l + 1) * val;
        t[i].lazy += val;
        return ;
    }
    push(i);

    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   update(i<<1, l, r, val);
    else if (l > mid)   update(i<<1|1, l, r, val);
    else update(i<<1, l, mid, val), update(i<<1|1, mid + 1, r, val);
    up(i);
}
void traverse(int i) {
    if (t[i].l == t[i].r) { cout << t[i].sum << ' '; return ;}
    push(i);
    traverse(i<<1); traverse(i<<1|1);
    up(i);
}
ll query2(int i, int idx) {
    if (idx == 0) return 0;
    if (t[i].l == t[i].r)   return t[i].sum;
    push(i);
    ll ans; int mid = t[i].l + t[i].r >> 1;
    if (idx <= mid) ans = query2(i<<1, idx);
    else ans = query2(i<<1|1, idx);
    up(i);
    return ans;
}
int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {scanf("%d", &a[i]); pre[i] = pre[i - 1] + a[i];}
    int type, l, r;
    build(1, 1, n);

    while (q--) {
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            printf("%lld\n", query(1, 1, r) - query(1, 1, l - 1) - query2(1, l - 1) * (r - l + 1));
        } else {
            update(1, l, n, - a[l] + r);
            a[l] = r;
        }
        // traverse(1); cout << endl;
    }
}