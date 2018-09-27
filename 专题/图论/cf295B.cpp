#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 505;

typedef long long ll;
int dp[MAX][MAX], a[MAX];
bool ok[MAX];
stack<ll>s;
int main() {
    int n; ios::sync_with_stdio(false); cin.tie(0); 
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)   cin >> dp[i][j];
    for (int i = 1; i <= n; ++i)    cin >> a[i];

    int u;
    long long ans;
    for (int k = n; k >= 1; --k) {
        u = a[k]; ok[u] = 1;
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        dp[i][j] = min(dp[i][j], dp[i][u] + dp[u][j]);


        ans = 0;
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        if (ok[i] && ok[j]) ans += dp[i][j];
        s.push(ans);
    }
    
    while (!s.empty()) {cout << s.top() << ' '; s.pop();}
    cout << endl;
}