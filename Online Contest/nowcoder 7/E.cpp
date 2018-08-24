#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector<int>G[100];
int main() {
    for (int k = 4; k <= 75; ++k) {
        long long ans = 1LL * k * (k - 1) * (k - 2) * (k - 3) / 24;
        cout << ans << endl;
    }
}