#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
const int INF = 1<<30;
struct Node {
    int l, r, Min;
}t[MAX*50];
int a[MAX], n, m, query[MAX], q, Max;
bool flag;
pair<int, int> ans[MAX], now;
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; 
    if (l == r) {t[i].Min = a[l]; return ;}
    int mid = l + r >> 1;
    build(i<<1, l, mid); build(i<<1|1, mid + 1, r);
    t[i].Min = min(t[i<<1].Min, t[i<<1|1].Min);
}
void update(int i) {
    if (t[i].l == t[i].r) {
        if (t[i].Min > now.second)  return ;
        now.second -= t[i].Min;
        now.first++;
        t[i].Min = INF;
        flag = true;
        return ;
    }
    if (t[i<<1].Min <= now.second)  update(i<<1);
    else if (t[i<<1|1].Min <= now.second)   update(i<<1|1);
    else return ;
    t[i].Min = min(t[i<<1].Min, t[i<<1|1].Min);
}
void traverse(int i) {
    if (t[i].l == t[i].r) {cout << t[i].Min << ' '; return ;}
    traverse(i<<1); traverse(i<<1|1);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)    scanf("%d", &a[i]);
    
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) scanf("%d", &query[i]), Max = max(Max, query[i]);


    now.first = 0; now.second = 0;
    build(1, 1, n);

    for (int i = 1; i <= Max; ++i) {
        if (now.first == n) {ans[i] = make_pair(now.first, now.second); continue;}
        now.second += m;
        while (true) {
            flag = false;
            update(1);
            if (!flag)  break;
        }
        ans[i] = make_pair(now.first, now.second);
    }

    for (int i = 1; i <= q; ++i) printf("%d %d\n", ans[query[i]].first, ans[query[i]].second);
}