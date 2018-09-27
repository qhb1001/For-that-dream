#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 305;
int fa[MAX], cnt[MAX], n, a[MAX], ans[MAX], idx[MAX], top;
vector<pair<int, int> >scc[MAX];
int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return ;
    if (cnt[v] > cnt[u])    swap(u, v);
    cnt[u] += cnt[v];
    fa[v] = u;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n; for (int i = 1; i <= n; ++i)  cin >> a[i];
    for (int i = 1; i <= n; ++i)    fa[i] = i, cnt[i] = 1;
    for (int i = 1; i <= n; ++i) {
        string in;
        cin >> in;
        for (int j = 1; j <= n; ++j) if (in[j - 1] == '1')  unit(i, j);
    }

    for (int i = 1; i <= n; ++i) scc[find(i)].push_back(make_pair(a[i], i));

    for (int i = 1; i <= n; ++i) if (scc[i].size() != 0) {
        int len = scc[i].size(); top = 0;
        for (int j = 0; j < len; ++j) idx[++top] = scc[i][j].second;
        sort(scc[i].begin(), scc[i].end());
        for (int j = 1; j <= top; ++j) ans[idx[j]] = scc[i][j - 1].first;
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;
    
}