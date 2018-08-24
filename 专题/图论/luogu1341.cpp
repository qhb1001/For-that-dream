#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <stack>
using namespace std;
const int MAX = 3000;
multiset<int>G[300];
int n, degree[MAX];
stack<char>ans;


void dfs(int u) {
    char v;
    char c =u;
    for (auto x = G[u].begin(); x != G[u].end(); x = G[u].begin()) {
        v = *x;
        G[u].erase(x);
        G[v].erase(G[v].find(u));
        dfs(v);
    }
    ans.push(u);
}
int main() {
    scanf("%d", &n);
    char s[3];
    char u, v;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s);
        u = s[0]; v = s[1];
        degree[u] += 1;
        degree[v] += 1;
        G[u].insert(v);
        G[v].insert(u);
    }
    
    int cnt = 0, idx = 0;
    for (int i = 1; i <= 300; ++i) if (degree[i]&1) {
        ++cnt;
        if (!idx)   idx = i;
    }
    
    if (cnt && cnt != 2)    {
        printf("No Solution\n");
        return 0;
    }
    
    if (!cnt) for (int i = 'A'; i <= 'z'; ++i) if (degree[i])   {idx = i; break;}
    
    dfs(idx);
    if (ans.size() != n + 1) printf("No Solution\n");
    else {
        while (!ans.empty())  {
            printf("%c", ans.top()); ans.pop();
        }
    }
    
}
