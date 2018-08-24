#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 20;
int n = 5, fa[MAX];
int find(int u) {
    return fa[u] == u? u : fa[u] = find(fa[u]);
}
bool unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    fa[u] = v;
    return true;
}
int main() {
    freopen("input.txt", "w", stdout);
    cout << 1 << '\n' << n << endl;
    for (int i = 1; i <= n; ++i)    fa[i] = i;
    srand((unsigned)time(NULL));
    for (int i = 1; i < n; ++i) cout << rand() % MAX + 1 << ' ' << rand() % MAX + 1 << endl;

    for (int i = 1; i < n; ++i) {
        while (true) {
            int u = rand() % n + 1, v = rand() % n + 1;
            if (unit(u, v)) {
                cout << u << ' ' << v << endl;
                break;
            }
        }
        
    }
}