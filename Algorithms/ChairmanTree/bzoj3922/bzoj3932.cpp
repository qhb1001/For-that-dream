#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
int root[MAX], L[MAX<<7], R[MAX<<7], num[MAX<<7], cnt, a[MAX], b[MAX];
ll sum[MAX<<7];
void build(int &i, int l, int r) {
    i = ++cnt;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(L[i], l, mid); build(R[i], mid + 1, r);
}
int update(int i, int l, int r, int idx, int val, int type) {
    int ii = ++cnt;
    
    //notice that should add the original value to 'sum'
    L[ii] = L[i]; R[ii] = R[i]; num[ii] = num[i] + type; sum[ii] = sum[i] + b[idx] * type;
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = update(L[ii], l, mid, idx, val, type);
    else    R[ii] = update(R[ii], mid + 1, r, idx ,val, type);
    return ii;
}
void update(int i, int l, int r, int idx, int type) {
    num[i] += type; sum[i] += b[idx] * type;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (idx <= mid) update(L[i], l, mid, idx, type);
    else update(R[i], mid + 1, r, idx, type);
}
ll query(int i, int l, int r, int k) {
    if (num[i] <= k)    return sum[i];
    int mid = l + r >> 1;
    if (l == r) return 1LL * k * b[l];
    if (k <= num[L[i]]) return query(L[i], l, mid, k);
    else return sum[L[i]] + query(R[i], mid + 1, r, k - num[L[i]]);
}
struct Node {
    int t, val, type;
    Node (int a = 0, int b = 0, int c = 0): t(a), val(b), type(c){}
    bool operator < (const Node b) const {
        return t <  b.t;
    }
}c[MAX<<2];
void traverse(int i, int l, int r) {
    if (l == r)  {cout << num[i] << ' '; return ;}
    int mid = l + r >> 1;
    traverse(L[i], l, mid); traverse(R[i], mid + 1, r);
}
int main() {
    int n, m; scanf("%d%d", &m, &n);
    int s, p, val;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &s, &p, &val);
        c[i<<1] = Node(s, val, 1);
        c[(i<<1) - 1] = Node(p + 1, val, -1);
        a[i] = b[i] = val;
    }
    sort(c + 1, c + 1 + m*2); sort(b + 1, b + 1 + m);
    int len = unique(b + 1, b + 1 + m) - b - 1;
    build(root[0], 1, len);
    
    int cnt_ = 1;
    for (int i = 1; i <= n; ++i) {
        bool flag = true;
        while (cnt_ <= m*2 && c[cnt_].t == i) {
            s = lower_bound(b + 1, b + 1 + len, c[cnt_].val) - b;
            int ttt = c[cnt_].val;
            root[i] = update(root[i - flag], 1, len, s, c[cnt_].val, c[cnt_].type);
            flag = false;
            ++cnt_;
        }
        if (flag)   root[i] = root[i - 1];
    }
    
    ll a, b, c ,pre = 1;
    int t, k;
    while (n--) {
        scanf("%d%lld%lld%lld", &t, &a, &b, &c);
        k = 1 + (a % c * pre % c+ b) % c;
        pre = query(root[t], 1, len, k);
        printf("%lld\n", pre);
    }
}
