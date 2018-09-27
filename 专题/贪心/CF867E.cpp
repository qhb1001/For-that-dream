#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e5 + 5;
struct Node {
    int val;
    bool tag;
    Node(int a = 0, bool b = 0): val(a), tag(b) {}
    bool operator < (const Node b) const {
        if (val != b.val)   return val > b.val;
        return tag < b.tag;
    }
}now;

int main() {
    priority_queue<Node>q;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long ans = 0;
        int val, n;
        cin >> n;
        while (n--) {
            cin >> val;
            if (!q.empty() && val > q.top().val) {
                now = q.top(); q.pop();
                ans += val - now.val;
                q.push(Node(val, 0));
                q.push(Node(val, 1));
            } else q.push(Node(val ,0));
        }
        
        int times = 0;
        while (!q.empty()) {
            now = q.top(); q.pop();
            if (now.tag)    times += 2;
        }
        cout << ans << ' ' << times << endl;
    }
}