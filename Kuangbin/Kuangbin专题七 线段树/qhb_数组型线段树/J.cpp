#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 5e4 + 5;
struct Node {
    int l, r, task, time;
    Node(int a = 0, int b = 0): task(a), time(b) {}
}t[MAX<<2], ans;
Node max(Node a, Node b) {
    if (a.time > b.time)    return a;
    return b;
}
struct Edge {
    int to, nex;
}e[MAX];
struct Range {
    int l, r;
    Range(int a = 0, int b = 0): l(a), r(b) {}
}range[MAX];
int head[MAX], cnt, dp[MAX], id[MAX], root, n;
bool in[MAX];
void add(int u, int v) {
    e[++cnt].to = v;
    e[cnt].nex = head[u];
    head[u] = cnt;
}

int getDP(int u) {
    dp[u] = 1;
    for (int i = head[u]; i; i = e[i].nex)      dp[u] += getDP(e[i].to);
    return dp[u];
}
void getID(int u) {
    id[u] = ++cnt;
    range[u] = Range(cnt, cnt + dp[u] - 1);
    for (int i = head[u]; i; i = e[i].nex)  getID(e[i].to);
}
void init() {
    memset(head, 0, sizeof(head));
    memset(in, 0, sizeof(in));
    cnt = 0;
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(v, u);
        in[u] = 1;
    }
    
    for (int i = 1; i <= n; ++i) if (in[i] == 0) {root = i; break;}
    getDP(root);
    cnt = 0;
    getID(root);
}

void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].time = t[i].task = -1;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
}
void assign_(int i, int l, int r, int task, int time) {
    if (t[i].l == l && t[i].r == r) {
        t[i].task = task;
        t[i].time = time;
        return ;
    }
    
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   assign_(i<<1, l, r, task, time);
    else if (l > mid)   assign_(i<<1|1, l, r, task, time);
    else {
        assign_(i<<1, l, mid, task, time);
        assign_(i<<1|1, mid + 1, r, task, time);
    }
}
Node query(int i, int id) {
    if (t[i].l == t[i].r)   return Node(t[i].task, t[i].time);
    
    int mid = t[i].l + t[i].r >> 1;
    if (id <= mid)  return max(t[i], query(i<<1, id));
    else    return max(t[i], query(i<<1|1, id));
}
void deal() {
    int q, idd, val;
    scanf("%d", &q);
    char s[2];
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        scanf("%s", s);
        if (s[0] == 'C') {
            scanf("%d", &idd);
            ans = query(1, id[idd]);
            printf("%d\n", ans.task);
        } else {
            scanf("%d%d", &idd, &val);
            assign_(1, range[idd].l, range[idd].r, val, i);
        }
    }
}
int main() {
//    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; ++k) {
        init();
        printf("Case #%d:\n", k);
        deal();
    }
}
