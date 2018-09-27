#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 305;
struct Node {
    int a, b, c, sum, id;
    bool operator < (const Node b) const {
        if (sum != b.sum)   return sum > b.sum;
        if (a != b.a)   return a > b.a;
        return id < b.id;
    }
}a[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].a >> a[i].b >> a[i].c;
        a[i].sum = a[i].a + a[i].b + a[i].c;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= 5; ++i) cout << a[i].id << ' ' << a[i].sum << endl;
    
}