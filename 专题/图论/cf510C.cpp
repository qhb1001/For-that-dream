#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX = 105;
string a[MAX];
vector<int>G[100];
int n, cnt, in[MAX];
char ans[MAX];
bool vis[MAX];
bool topoSort() {
    queue<int>q;
    int u, v;
    for (int i = 0; i < 26; ++i) if (vis[i] && in[i] == 0) q.push(i);

    while (!q.empty()) {
        u = q.front(); q.pop();
        ans[++cnt] = u + 'a';
        int len = G[u].size();
        for (int i = 0; i < len; ++i) {
            v = G[u][i];
            --in[v]; 
            if (!in[v]) q.push(v);
        }
    }

    for (int i = 0; i < 26; ++i) if (in[i])  return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)    cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        string x = a[i - 1], b = a[i];
        if (x.size() < b.size() && x.substr(0, x.size()) == b.substr(0, x.size())) continue;
        if (x.size() > b.size() && x.substr(0, b.size()) == b.substr(0, b.size()))  {cout << "Impossible\n"; return 0;}
        
        for (int j = 0; j < min(x.size(), b.size()); ++j) if (x[j] != b[j]) {
            G[x[j] - 'a'].push_back(b[j] - 'a');
            in[b[j] - 'a']++;
            vis[x[j] - 'a'] = vis[b[j] - 'a'] = 1;
            break;
        }
    }

    if (topoSort() == 0) cout << "Impossible\n";
    else {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= cnt; ++i) {cout << ans[i]; vis[ans[i] - 'a'] = 1;}
        for (int i = 0; i < 26; ++i) if (!vis[i])   cout << (char)(i + 'a');
        cout << endl;
    }
}