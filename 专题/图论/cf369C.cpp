#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;
int head[MAX], cnt, n;
struct Edge {
    int to, nex, isProblem;
}e[MAX<<2];
vector<int>ans;
inline void add(int u, int v, int t) {
    e[++cnt] = (Edge) {v, head[u], t};
    head[u] = cnt;
}
int dfs(int u, int fa) {
    int ans_ = 0, t;
    for (int i = head[u], v; i; i = e[i].nex) {
        v = e[i].to; if (v == fa)   continue;
        if (e[i].isProblem == 2)    {
            t = dfs(v, u);
            ans_ += max(1, t);
            if (t >= 1) continue;
            else ans.push_back(v);
        }
        else ans_ += dfs(v, u);
    }
    return ans_;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for (int i = 1, x, y, c; i < n; ++i) {
        cin >> x >> y >> c;
        add(x, y, c);
        add(y, x, c);
    }
    cout << dfs(1, -1) << endl;
    for (int i = 0; i < ans.size(); ++i)    cout << ans[i] << ' ';
    cout << endl;
}