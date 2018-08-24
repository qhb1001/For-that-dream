#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1e3 + 5;
char G[MAX][MAX];
ll letter[130];
int row, col;
void preTreatment() {
    int cnt = 1;
    for (char c = 'a'; c <= 'z'; ++c)   {
        letter[c] = (1LL<<(cnt++));
        // cout << letter[c] << endl;
    }
    for (char c = 'A'; c <= 'Z'; ++c)   {
        letter[c] = (1LL<<(cnt++));
        // cout << letter[c] << endl;
    }
}
struct Node {
    int l, r;
    ll now;
}t[MAX][MAX<<2];
void build(Node* t, int i, int j, int l, int r) {
    t[i].l = l; t[i].r = r;
    if (l == r) {t[i].now = letter[G[l][j]];  return ;}
    int mid = l + r >> 1;
    build(t, i<<1, j, l, mid);
    build(t, i<<1|1, j, mid + 1, r);
    ll a = t[i<<1].now, b = t[i<<1|1].now;
    if (a&b)    t[i].now = a|b|1;
    else    t[i].now = a|b;
}
ll query(Node* t, int i, int l, int r) {
    if (t[i].l == l && t[i].r == r) return t[i].now;
    int mid = t[i].l + t[i].r >> 1;
    if (r <= mid)   return query(t, i<<1, l, r);
    else if (l > mid)   return query(t, i<<1|1, l, r);
    else {
        ll a = query(t, i<<1, l, mid), b = query(t, i<<1|1, mid + 1, r);
        if (a&b)    return a|b|1;
        else    return a|b;
    }
}
void input() {
    scanf("%d%d", &row, &col);
    for (int i = 1; i <= row; ++i)  scanf("%s", G[i] + 1);
    for (int i = 1; i <= col; ++i) build(t[i], 1, i, 1, row);
}
ll deal() {
    ll ans = 0, now, add;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {

            //开始枚举竖直边的长度
            for (int len = 1; i + len - 1 <= row && len <= 52; ++len) {
                now = 0;
                //开始枚举上边的长度
                for (int k = 1; k + j - 1 <= col && k <= 52; ++k) {
                    add = query(t[j + k - 1], 1, i, i + len - 1);
                    // if (i == 1 && j == 1 && len == 1 && k == 4) {
                    //     bitset<53>a(add), b(now);
                    //     cout << a << endl << b << endl;
                    // }
                    if ((add&now) || (add&1))    break;
                    now |= add;
                    ++ans;
                    // printf("%d %d %d %d\n", i, j, i + len - 1, j + k - 1);
                }

            }
        }
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.a", "w", stdout);
    preTreatment();
    input();
    printf("%lld\n", deal());
}