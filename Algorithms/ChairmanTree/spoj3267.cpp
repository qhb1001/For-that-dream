#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 3e4 + 5;
const int MAXX = 1e6 + 5;
int root[MAX], L[MAX<<7], R[MAX<<7], num[MAX<<7], cnt, a[MAX], last[MAXX];
void build(int &i, int l, int r) {
    i = ++cnt;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(L[i], l, mid);
    build(R[i], mid + 1, r);
} 
int update(int i, int l, int r, int idx, int val) {
    int ii = ++cnt; L[ii] = L[i]; R[ii] = R[i]; num[ii] = num[i] + val;
    if (l == r) return ii;
    int mid = l + r >> 1;
    if (idx <= mid) L[ii] = update(L[ii], l, mid, idx, val);
    else R[ii] = update(R[ii], mid + 1, r, idx, val);
    return ii;
}
int query(int i, int l, int r, int ll, int rr) {
    if (ll == l && rr == r) return num[i];
    int mid = l + r >> 1;
    if (rr <= mid)  return query(L[i], l, mid, ll, rr);
    else if (ll > mid)  return query(R[i], mid + 1, r, ll, rr);
    else return query(L[i], l, mid, ll, mid) + query(R[i], mid + 1, r, mid + 1, rr);
}
void traverse(int i, int l, int r) {
    if (l == r) {cout << num[i] << ' '; return ;}
    int mid = l + r >> 1;
    traverse(L[i], l, mid); traverse(R[i], mid + 1, r);
}
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);

    build(root[n + 1], 1, n);
    for (int i = n; i >= 1; --i) {
        if (!last[a[i]])    root[i] = update(root[i + 1], 1, n, i, 1);
        else {
            root[i] = update(root[i + 1], 1, n, i, 1);
            root[i] = update(root[i], 1, n, last[a[i]], -1);
        }
        last[a[i]] = i;
    }

    scanf("%d", &m);
    int l, r;
    while (m--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(root[l], 1, n, l, r));
    }
}