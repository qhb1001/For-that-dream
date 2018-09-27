#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
map<pair<int, int>, int>mp;
int n, len, cnt, idx;
pair<int, int>now, dp[MAX];
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        mp.clear(); cnt = 0;
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            scanf("%d", &len);
            for (int i = 1; i <= len; ++i) {
                scanf("%d%d", &now.first, &now.second); // first as times second as last
                if (mp.count(now) == 0) {
                    idx = ++cnt; mp[now] = idx; 
                    dp[idx] = make_pair(1, k); 
                    ans = max(1, ans);
                }
                else {
                    idx = mp[now];
                    if (dp[idx].second == k - 1) dp[idx].first++, dp[idx].second = k;
                    else dp[idx] = make_pair(1, k);
                    ans = max(ans, dp[idx].first);
                }
            }
        }


        printf("%d\n", ans);
    }
}