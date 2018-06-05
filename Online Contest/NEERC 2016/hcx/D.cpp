#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
ll dp[MAX];
string a;
bool check(string now) {
    if (now == "NW" || now == "NE" ||
        now == "SW" || now == "SE") return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> a;
    int len = a.size();
    dp[0] = 1;
    string temp = "";
    temp+=a[0];temp+=a[1];
    dp[1] = 1;
    if (check(temp))    dp[1]++;
    for (int i = 2; i < len; ++i) {
        dp[i] = dp[i - 1];
        temp = a[i - 1];
        temp += a[i];
//        temp=a[i-1]+a[i];
        if (check(temp)) dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }

    cout << dp[len - 1] << endl;
}
