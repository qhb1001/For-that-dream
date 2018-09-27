#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
const int MAX = 2e5 + 5;
set<int>s[MAX];
vector<int>G[MAX];
int n, a[MAX];
bool solve() {
    queue<int>q;
    q.push(1);
    int cnt = 2, u, v, len;
    while (!q.empty()) {
        u = q.front(); q.pop();
        len = G[u].size();
        if (u != 1) len--;

        for (int i = 1; i <= len; ++i) {
            if (s[u].find(a[cnt]) != s[u].end()) {q.push(a[cnt]); ++cnt;}
            else return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        s[u].insert(v);
        s[v].insert(u);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (solve())    cout << "YES\n";
    else cout << "NO\n";
}