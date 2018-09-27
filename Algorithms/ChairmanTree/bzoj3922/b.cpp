#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#define mid (((l) + (r)) / 2)
using namespace std;

inline int ReadInt() {
    static int n, ch;
    n = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
    return n;
}

typedef long long ll;
const int maxn = 100000 + 3;
struct SegNode *pit, *null;
struct SegNode {
    SegNode *ls, *rs;
    ll s, sum;
    inline void maintain() {
        s = ls->s + rs->s;
        sum = ls->sum + rs->sum;
    }
    void *operator new(size_t) {return pit++;}
    SegNode(): s(0), sum(0) {ls = null, rs = null;}
}pool[maxn * 18 * 2], *root[maxn];

int n, m, S[maxn], E[maxn], P[maxn]; //n 任务总数 m 时间范围

vector<int> ps;
void compress() {
    for (int i = 0; i < m; ++i)
        ps.push_back(P[i]);
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    for (int i = 0; i < m; ++i)
        P[i] = lower_bound(ps.begin(), ps.end(), P[i]) - ps.begin();
}

void init() {
    pit = pool;
    null = new SegNode();
    null->s = 0, null->sum = 0;
    null->ls = null, null->rs = null;
}

struct state {
    int t, p, op;
    state(int t, int p, int op): t(t), p(p), op(op) {}
    bool operator < (const state &s) const {
        return t < s.t;
    }
};

SegNode *modify(const SegNode *o, int l, int r, int v, int op) {
    if (l >= r) return null;
    SegNode *ne = new SegNode();
    *ne = *o;
    if (r - l == 1) {
        ne->s += op;
        ne->sum += ps[v] * op;
        return ne;
    }
    if (v < mid) ne->ls = modify(ne->ls, l, mid, v, op);
    else ne->rs = modify(ne->rs, mid, r, v, op);
    ne->maintain();
    return ne;
}

ll query(const SegNode *o, int l, int r, int k) {
    if (l >= r || k == 0) return 0;
    if (o->s <= k) return o->sum;
    if (r - l == 1) return (ll)ps[l] * k;
    if (k <= o->ls->s) return query(o->ls, l, mid, k);
    else return o->ls->sum + query(o->rs, mid, r, k - o->ls->s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.b", "w", stdout);
    init();
    m = ReadInt(), n = ReadInt();
    for (int i = 0; i < m; ++i)
        S[i] = ReadInt() - 1, E[i] = ReadInt(), P[i] = ReadInt(); //[S, E)
    compress(); //离散
    vector<state> events;
    for (int i = 0; i < m; ++i)
        events.push_back(state(S[i], P[i], 1)), events.push_back(state(E[i], P[i], -1)); //时间结束的时候，需要减!
    sort(events.begin(), events.end());
    for (int i = 0, j = 0; i < n; ++i) {
        SegNode *now = null;
        if (i) now = root[i - 1];
        while (j < events.size() && events[j].t == i) {
            now = modify(now, 0, ps.size(), events[j].p, events[j].op);
            ++j;
        }
        root[i] = now;
    }
    ll pre = 1, k;
    while (n--) {
        int x = ReadInt() - 1, a = ReadInt(), b = ReadInt(), c = ReadInt();
        k = 1 + (a * pre + b) % c;
        printf("%lld\n", pre = query(root[x], 0, ps.size(), k));
    }
    return 0;
}
