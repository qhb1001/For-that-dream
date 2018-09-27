#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 5;
deque<int>q;

int main() {
    int n, T, a, t1, t2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        //init
        while (q.empty() == 0)  q.pop_back();
        long long ans = 0;
        int times = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a);
            
            while (q.empty() == 0 && q.back() > a) {
                if (q.size() < 2)   break;
                t1 = q.front(); t2 = q.back();
                if (t2 == t1)   break;
                ans += t2 - t1;
                times += 2;
                q.pop_back();
                q.pop_front();
            }
            
            while (q.empty() == 0 && q.back() > a)  q.pop_back();
            q.push_back(a);
        }
        while (true) {
            if (q.size() < 2)   break;
            t1 = q.front(); t2 = q.back();
            if (t2 == t1)   break;
            ans += t2 - t1;
            times += 2;
            q.pop_back();
            q.pop_front();
        }

        printf("%lld %d\n", ans, times);
    }
}