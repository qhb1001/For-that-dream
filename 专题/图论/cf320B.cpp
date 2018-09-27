#include <iostream>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define P pair<int, int>
using namespace std;
const int MAX = 105;
vector<P> range;
int len;
bool bfs(int s, int t) {
    P now;
    bool vis[MAX] = {0};
    queue<P>q;
    q.push(range[s]);
    vis[s] = 1;
    while (!q.empty()) {
        now = q.front(); q.pop();
        for (int i = 0; i < range.size(); ++i) {
            if (!vis[i] && ((range[i].first < now.first && range[i].second > now.first) 
            || (range[i].first < now.second && range[i].second > now.second))) {
                q.push(range[i]);
                vis[i] = 1;
                if (i == t) return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, op, l, r; cin >> n;
    while (n--) {
        cin >> op >> l >> r;
        if (op == 1) {
            range.push_back(P(l, r));
        } else {
            if (bfs(l - 1, r - 1)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    } 
}