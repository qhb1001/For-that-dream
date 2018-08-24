#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
struct Node {
    int val, t;
    Node(int a = 0, int b = 0): val(a), t(b) {}
    bool operator < (const Node b) const {
        return val < b.val;
    }
}good[MAX], now;
bool cmp (Node a, Node b) {
    if (a.t != b.t) return a.t < b.t;
    else    return a.val < b.val;
}
int main() {
    int n, a, b;
    while (scanf("%d", &n) != EOF) {
        priority_queue<Node>q;
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &good[i].val, &good[i].t);
        }
        sort(good + 1, good + 1 + n, cmp);

        q.push(Node(0, 0));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            while (q.empty() == 0 && q.top().t >= good[i].t) {
                ans = max(ans, q.top().val);
                q.pop();
            }

            now = q.top();
            now.val += good[i].val;
            now.t += 1;
            ans = max(now.val, ans);
            q.push(now);
        }
        printf("%d\n", ans);
    }
}