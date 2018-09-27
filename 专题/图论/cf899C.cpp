#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 6e4 + 5;
vector<int>ans;
int main() {
    int n; cin >> n;
    long long sum = (1LL * (n + 1) * n) / 4;
    long long sum_;
    for (int i = n; i >= 1; --i) {
        if (sum >= i)   {sum -= i; ans.push_back(i);}
    }

    sum = (1LL * (n + 1) * n) / 4 - sum;
    sum_ = (1LL * (n + 1) * n) / 2 - sum;
    cout << abs(sum - sum_) << endl << ans.size() << ' ';
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << endl;
}