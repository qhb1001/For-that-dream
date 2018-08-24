#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 1e5 + 5;
struct Node1 {
    int l, r, max_;
}t[MAX<<2];
int a[MAX];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r;
    if (l == r) {
        t[i].max_ = a[l];
        return ;
    }
    
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    t[i].max_ = max(t[i<<1].max_, t[i<<1|1].max_);
}
int query1(int i, int l, int r, int val) {//find the first value that is bigger than val
    if (l > r)  return 0;
    if (t[i].max_ <= val)   return 0;
    int mid = t[i].l + t[i].r >> 1;
    if (t[i].l == l && t[i].r == r) {
        if (l == r) return l;
        if (t[i<<1].max_ > val) return query1(i<<1, l, mid, val);
        else if (t[i<<1|1].max_ > val)  return query1(i<<1|1, mid + 1, r, val);
        else    return 0;
    }
    
    if (r <= mid)   return query1(i<<1, l, r, val);
    else if (l > mid)   return query1(i<<1|1, l, r, val);
    else {
        int t = query1(i<<1, l, mid, val);
        if (t != 0) return t;
        return query1(i<<1|1, mid + 1, r, val);
    }
}
int query2(int i, int l, int r) {//find the maximum value in range [l, r]
    if (l > r)  return 0;
    if (t[i].l == l && t[i].r == r)     return t[i].max_;
    
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query2(i<<1, l, r);
    else if (l > mid)   return query2(i<<1|1, l, r);
    else    return max(query2(i<<1, l, mid), query2(i<<1|1, mid + 1, r));
}
int dp[MAX], n, q, idx, val, nex[MAX], lst;
bool isCritical[MAX];
void deal() {
    build(1, 1, n);
    dp[n] = 1;
    memset(isCritical, 0, sizeof(isCritical));
    nex[n] = 0;
    for (int i = n - 1; i >= 1; --i) {
        idx = query1(1, i + 1, n, a[i]);
        dp[i] = dp[idx] + 1;
        nex[i] = idx;
    }
    idx = 1;
    while (idx) {
        isCritical[idx] = 1;
        idx = nex[idx];
    }
    isCritical[idx] = 1;
    lst = idx;
}
int query3(int i, int l, int r, int val) {//find the first value that is equal to val
    if (t[i].l == t[i].r)   return l;
    
    int mid = t[i].l + t[i].r >> 1, tt;
    if (t[i].l == l && t[i].r == r) {
        if (t[i<<1].max_ == val)    return query3(i<<1, l, mid, val);
        else if (t[i<<1|1].max_ == val) return query3(i<<1|1, mid + 1, r, val);
        else    return 0;
    }
    
    if (r <= mid)   return query3(i<<1, l, r, val);
    else if (l > mid)   return query3(i<<1|1, l, r, val);
    else {
        tt = query3(i<<1, l, mid, val);
        if (tt != 0) return tt;
        return query3(i<<1|1, mid + 1, r, val);
    }
    
}
int main() {
//    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)    scanf("%d", &a[i]);
        deal();
        
        while (q--) {
            scanf("%d%d", &idx, &val);
            if (n == 1) {
                printf("1\n");
                continue;
            }
            
            if (idx == 1) {
//                cout << query1(1, 2, n, val) << endl;
                printf("%d\n", dp[query1(1, 2, n, val)] + 1);
            } else {
                if (isCritical[idx]) {
                    if (val <= query2(1, 1, idx - 1))   printf("%d\n", dp[query1(1, idx + 1, n, query2(1, 1, idx - 1))] + dp[1] - dp[query3(1, 1, idx - 1, query2(1, 1, idx - 1))] + 1);
                    else    printf("%d\n", dp[1] - dp[idx] + 1 + dp[query1(1, idx + 1, n, val)]);
                } else {
                    if (val <= query2(1, 1, idx - 1))   printf("%d\n", dp[1]);
                    else    printf("%d\n", dp[query1(1, idx + 1, n, val)] + dp[1] - dp[query3(1, 1, idx - 1, query2(1, 1, idx - 1))] + 2);
                }
            }
        }
    }
}
