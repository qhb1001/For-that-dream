#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<char>t[1000];
bool in[1000], vis[1000];
void dfs(char c) {
    if (c == '*')   return ;
    cout << c;
    dfs(t[c][0]);
    dfs(t[c][1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string now;
    for (int i = 1; i <= n; ++i) {
        cin >> now;
        int len = now.size();
        t[now[0]].push_back(now[1]);
        t[now[0]].push_back(now[2]);
        in[now[1]] = 1;
        in[now[2]] = 1;
        vis[now[0]] = vis[now[1]] = vis[now[2]] = 1;
    }

    for (int i = 0; i < 1000; ++i) if (vis[i] && !in[i]) {
        dfs(i);
        break;
    }

}