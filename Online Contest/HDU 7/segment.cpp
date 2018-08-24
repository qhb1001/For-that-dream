#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 5e8;
bool vis[MAX];
int main() {
    long long ans = 0;
    for (int i = 1; i <= MAX; ++i) {
        if (!vis[MAX / i])  {
            vis[MAX / i] = 1;
            ++ans;
        }
    }

    printf("%lld\n", ans);
}
