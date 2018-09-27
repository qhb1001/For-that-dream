#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define work 0
#define down 1
const int MAX = 105;
int n, m, degree[MAX];
bool point[MAX];
vector<int>G[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        degree[u]++; degree[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0, temp[MAX];;
    while (true) {
        bool flag = false;
        memcpy(temp, degree, sizeof(degree));
        for (int i = 1; i <= n; ++i) {
            if (temp[i] == 1 && point[i] == work) {
                flag = true;
                for (int v : G[i]) {
                    degree[v]--;
                } 
                point[i] = down;
            }
        }
        ans += flag;
        if (!flag)  break;
    }

    cout << ans << endl;
}