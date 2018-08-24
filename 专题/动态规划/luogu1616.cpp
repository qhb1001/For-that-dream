#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
int dp[MAX];
int main() {
    int T, m, t, val;
    scanf("%d%d", &T, &m);
    while (m--) {
        scanf("%d%d", &t, &val);
        for (int i = t; i <= T; ++i) dp[i] = max(dp[i], dp[i - t] + val);
    }

    printf("%d\n", dp[T]);
}