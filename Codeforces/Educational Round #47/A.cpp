#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1005;
int c[MAX];
queue<int>q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)    cin >> c[i];
    for (int i = 1; i <= m; ++i)    {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i] <= q.front()) {
            ++ans;
            q.pop();
        }
        if (q.empty())  break;
    }
    cout << ans << endl;
}