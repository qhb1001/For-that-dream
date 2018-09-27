#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
const int MAX = 5e4 + 5;
const int INF = 1<<30;
using namespace std;
int n, X[MAX], Y[MAX];
pair<int, int> in[MAX];
map<int, int>XX, YY;
struct Node {
    int l, r, Min, lazy, len;
}t[2][MAX<<4];
void discrete() {
    sort(X + 1, X + 1 + n);
    sort(Y + 1, Y + 1 + n);
    for (int i = 1; i <= n; ++i) XX[X[i]] = i, YY[Y[i]] = i;
}
void build(Node*t, int i, int l, int r) {
    t[i].l = l; t[i].r = r; t[i].len = r - l + 1; t[i].Min = INF;
    if (l == r) return ;
    int mid = l + r >> 1;
    build(t, i<<1, l, mid);
    build(t, i<<1|1, mid + 1, r);
}
int ans;
void update(Node* t, int i, int l, int r, int val) {
    if (t[i].l == t[i].r) {if (t[i].Min != INF) ans -= val - t[i].Min; t[i].Min = val; return ;}
    int mid = t[i].l + t[i].r >> 1;
    
}

int main() {
    int n; scanf("%d", &n);


}