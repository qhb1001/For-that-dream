#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
struct Node {
    int sum, id;
    bool operator < (const Node b) const {
        if (sum != b.sum)   return sum > b.sum;
        return id < b.id;
    }
}a[1005];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = 1; j <= 4; ++j) {
            int t;
            cin >> t;
            sum += t;
        }
        a[i].sum = sum;
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n);
    int ans;
    for (int i = 1; i <= n; ++i) {
        if (a[i].id == 1) {
            cout << i << endl;
            return 0;
        }
    }
}
