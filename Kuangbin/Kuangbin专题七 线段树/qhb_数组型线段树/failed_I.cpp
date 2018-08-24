#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 5e4 + 5;
struct Node {
    int l, r, ok;
}t[MAX<<2];
void build(int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].ok = 1;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(i<<1, l, mid);
    build(i<<1|1, mid + 1, r);
}
void update(int i, int id, int type) {
    if (t[i].l == t[i].r) {
        t[i].ok = type;
        return ;
    }
    int mid = t[i].l + t[i].r >> 1;
    if (id <= mid)  update(i<<1, id, type);
    else    update(i<<1|1, id, type);
    t[i].ok = t[i<<1].ok & t[i<<1|1].ok;
}
int ans, ss[MAX], top;
int query2(int i, bool type) {//if type == 0 then look for the left segment
    if (t[i].ok == 1)   {
        ans += t[i].r - t[i].l + 1;
        return 3;
    }

    if (t[i].l == t[i].r)   return 0;

    int mid = t[i].l + t[i].r >> 1, a = 0, b = 0;
    if (type == 0) {
        a = query2(i<<1, 0);
        if (a&2)    b = query2(i<<1|1, 0);
        return (a&1) | (b&2);
    } else {
        a = query2(i<<1|1, 1);
        if (a&1)    b = query2(i<<1, 1);
        return (a&2) | (b&1);
    }
}
int query1(int i, int id) {
    if (t[i].ok == 1) {
        ans += t[i].r - t[i].l + 1;
        return 3;
    }

    if (t[i].l == t[i].r)   return 0;

    int mid = t[i].l + t[i].r >> 1, a, b = 0;
    if (id <= mid) {
        a = query1(i<<1, id);
        if (a&2)    b = query2(i<<1|1, 0);
        return (a&1) | (b&2);
    } else {
        a = query1(i<<1|1, id);
        if (a&1)    b = query2(i<<1, 1);
        return (a&2) | (b&1);
    }
}


void traverse(int i) {
    if (t[i].l == t[i].r) {
        cout << t[i].ok << ' ';
        return ;
    }
    traverse(i<<1); traverse(i<<1|1);
}
int main() {
    // freopen("input.txt", "r", stdin);
    int n, q, id;
    char s[2];
    while (scanf("%d%d", &n, &q) != EOF) {
        build(1, 1, n);
        top = 0;
        while (q--) {
            scanf("%s", s);
            if (s[0] == 'R' && top) {
                update(1, ss[top--], 1);
                // traverse(1);
                // cout << endl;
            } else if (s[0] == 'D') {
                scanf("%d", &id);
                update(1, id, 0);
                ss[++top] = id;
            } else {
                scanf("%d", &id);
                ans = 0;
                query1(1, id);
                printf("%d\n", ans);
            }
        }
    }
    
}