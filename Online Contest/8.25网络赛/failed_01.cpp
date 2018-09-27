#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
const int INF = 1<<30;
struct Node {
    int l, r;
    pair<int, int>p;
}t[MAX<<2];
int a[MAX];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r;
    if (l == r) {
        t[i].p.first = a[l];
        t[i].p.second = l;
        return ;
    }
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
    t[i].p = min(t[i<<1].p, t[i<<1|1].p);
}
pair<int, int> query(int i, int l, int r) {
    if (t[i].l == l && t[i].r == r) return t[i].p;
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(i<<1, l, r);
    else if (l > mid)   return query(i<<1|1, l, r);
    else return min(query(i<<1, l, mid), query(i<<1|1, mid + 1, r));
}
void update(int i, int id) {
    if (t[i].l == t[i].r) {
        t[i].p.first = INF;
        return ;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (id <= mid)  update(i<<1, id);
    else    update(i<<1|1, id);
    t[i].p = min(t[i<<1].p, t[i<<1|1].p);
}
vector<pair<int, int> >p;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}
int main() {
    int n, T;
    scanf("%d", &T);
    while (T--) {
        p.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)    {
            scanf("%d", &a[i]);
            p.push_back(make_pair(a[i], i));
        }
        build(1, 1, n);
        long long ans = 0;
        int times = 0;
        pair<int, int>now;
        sort(p.begin(), p.end(), cmp);
        // cout << "here:";
        for (int i = 0; i < n; ++i) {
            // cout << p[i].first << ' ';
            if (p[i].second == 1)   continue;
            now = query(1, 1, p[i].second - 1);
            if (p[i].first > now.first) {
                ans += p[i].first - now.first;
                update(1, now.second);
                times += 2;
            }
        }

        // cout << endl;
        printf("%lld %d\n", ans, times);
    }
}