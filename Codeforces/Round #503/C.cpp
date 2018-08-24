#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 3005;

vector<int>price[MAX];
vector<int>remaining;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, belong;
    long long cost;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> belong >> cost;
        price[belong].push_back(cost);
    }

    for (int i = 2; i <= m; ++i)    sort(price[i].begin(), price[i].end());

    int temp, needed;
    long long ans = 1LL<<50;
    for (int votes = 1; votes <= n; ++votes) {
        temp = price[1].size();
        needed = votes - temp;
        cost = 0;
        remaining.clear();
        for (int j = 2; j <= m; ++j) {
            int id = max((int)price[j].size() - (votes - 1), 0);
            for (int k = 0; k < id; ++k) {
                cost += price[j][k];
                needed--;
            }

            for (int k = id; k < price[j].size(); ++k) {
                remaining.push_back(price[j][k]);
            }
        }

        if (needed > 0) {
            nth_element(remaining.begin(), remaining.begin() + needed, remaining.end());
            for (int j = 0; j < needed; ++j) cost += remaining[j];
        }

        ans = min(ans, cost);
    }

    cout << ans << endl;
}