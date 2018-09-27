#include <iostream>
#include <cstdio>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <map>
using namespace std;
const int MAX = 2e5 + 5;
int n, m, k, degree[MAX];
set<pair<int, int> >q;
pair<int, int> e[MAX], now;
vector<int>G[MAX];
stack<int>ans;
map<pair<int, int>, int>vis;
bool delete_[MAX];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        cin >> e[i].first >> e[i].second;
        degree[e[i].first]++;
        degree[e[i].second]++;
        G[e[i].first].push_back(e[i].second);
        G[e[i].second].push_back(e[i].first);
    }

    for (int i = 1; i <= n; ++i)    q.insert(make_pair(degree[i], i));
    
    int u, v;
    while (!q.empty() && q.begin()->first < k) {
        now = *q.begin(); q.erase(q.begin());
        u = now.second; delete_[u] = 1;
        for (int i = 0; i < G[u].size(); ++i) {
            v = G[u][i]; now = make_pair(u, v); 
            if (vis.find(now) != vis.end())   continue;
            else {
                vis[now] = 1;
                swap(now.first, now.second);
                vis[now] = 1;
            }
            now = *q.find(make_pair(degree[v], v)); q.erase(q.find(make_pair(degree[v], v)));
            degree[v]--;
            q.insert(make_pair(degree[v], v));
        }
    }


    for (int i = m; i >= 1; --i) {
        ans.push(q.size());

        now = make_pair(e[i].first, e[i].second);
        if (vis.find(now) != vis.end()) continue;
        else {
            vis[now] = 1;
            swap(now.first, now.second);
            vis[now] = 1;
        }


        u = e[i].first;
        if (!delete_[u]) {
            now = *q.find(make_pair(degree[u], u));  q.erase(q.find(make_pair(degree[u], u)));
            degree[now.second]--;
            q.insert(make_pair(degree[u], u));
        }

        u = e[i].second;
        if (!delete_[u]) {
            now = *q.find(make_pair(degree[u], u));  q.erase(q.find(make_pair(degree[u], u)));
            degree[now.second]--;
            q.insert(make_pair(degree[u], u));
        }

        while (!q.empty() && q.begin()->first < k) {
            now = *q.begin(); q.erase(q.begin());
            u = now.second; delete_[u] = 1;
            for (int i = 0; i < G[u].size(); ++i) {
                v = G[u][i]; now = make_pair(u, v); 
                if (vis.find(now) != vis.end())   continue;
                else {
                    vis[now] = 1;
                    swap(now.first, now.second);
                    vis[now] = 1;
                }

                now = *q.find(make_pair(degree[v], v)); q.erase(q.find(make_pair(degree[v], v)));
                degree[v]--;
                q.insert(make_pair(degree[v], v));
            }
        }
    }

    while (!ans.empty()) {cout << ans.top() << endl; ans.pop();}

}