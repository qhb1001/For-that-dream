#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int MAX = 1e5 + 5;
typedef long long ll;
vector<pair<ll, ll> >range;
set<ll>s;
bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second != b.second)   return a.second < b.second;
    return a.first < b.first;
}
struct Node {
    int l, r, num, len;
}t[MAX<<7];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].num = 0; t[i].len = t[i].r - t[i].l + 1;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
}
int ans;
int update_(int i, int l, int r) {
    if (t[i].num == t[i].len)   return -1;
    if (l == r) {
        t[i].num = 1;
        return l;
    }
    int mid = l + r >> 1, tt;
    if (t[i<<1].num < t[i<<1].len)    tt = update_(i<<1, l, mid);
    else tt = update_(i<<1|1, mid + 1, r);
    t[i].num = t[i<<1].num + t[i<<1|1].num;
    return tt;
}
int update(int i, int l, int r) {
    int ttt;
    int mid = t[i].l + t[i].r >> 1;
    if (t[i].l == l && t[i].r == r) return update_(i, l, r);
    
    
    if (r <= mid)   ttt = update(i<<1, l, r);
    else if (l > mid)   ttt = update(i<<1|1, l, r);
    else {
        ttt = update(i<<1, l, mid);
        if (ttt == -1)  ttt = update(i<<1|1, mid + 1, r);
    }
    t[i].num = t[i<<1].num + t[i<<1|1].num;
    return ttt;
}

void traverse(int i) {
    if (t[i].l == t[i].r)   {cout << t[i].num << ' '; return ;}
    traverse(i<<1); traverse(i<<1|1);
}
int main() {
    freopen("input.txt", "r", stdin);
    int T; scanf("%d", &T);
    while (T--) {
        ll n, m, l, r, t; scanf("%lld%lld", &m, &n);
        range.clear(); s.clear();build(1, 0, 2*m);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &l, &r);
            if (l <= r) range.push_back(make_pair(l, r)), range.push_back(make_pair(l + m, r + m));
            else range.push_back(make_pair(l, r + m));
        }
        sort(range.begin(), range.end(), cmp);
        int len = range.size();
        bool flag = true;
        for (int i = 0; i < len; ++i) {
            l = range[i].first; r = range[i].second;
            cout << l << ' ' << r << endl;
            if (update(1, l, r) == -1) {flag = false; break;}
            for (int j = 0; j <= m*2; ++j)  printf("%d ", j); cout << endl;
            traverse(1); cout << endl;
        }
        printf("%s\n", flag?"YES":"NO");
    }
}
