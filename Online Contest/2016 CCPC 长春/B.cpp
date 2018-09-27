#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll a[15], b[15];
int n;
struct Fraction {
    ll b, a;
};
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
Fraction dfs(int cnt) {
    if (cnt == n) {
        ll GCD = gcd(a[n], b[n]);
        return (Fraction){b[n] / GCD, a[n] / GCD};
    } 

    Fraction temp = dfs(cnt + 1);
    temp.b += temp.a * a[cnt];
    ll GCD = gcd(temp.a, temp.b);
    temp.a /= GCD; temp.b /= GCD;

    Fraction ans = (Fraction) {temp.a * b[cnt], temp.b};
    GCD = gcd(ans.a, ans.b);
    ans.a /= GCD; ans.b /= GCD;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, kase = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << "Case #" <<  kase++ << ": ";
        for (int i = 1; i <= n; ++i)    cin >> a[i];
        for (int j = 1; j <= n; ++j)    cin >> b[j];

        Fraction ans = dfs(1);
        cout << ans.b << ' ' << ans.a << endl;
    }
}