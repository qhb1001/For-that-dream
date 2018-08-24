#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll Pow(ll a, int b, int p) {
    a%=p; ll ans=1;
    for(; b; b>>=1, a=a*a%p)
        if(b&1) ans=ans*a%p;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll t1 = ((Pow(2, a+c, mod) * (1+b+d) + Pow(2, a, mod) * (Pow(2, b, mod) - b - 1)) % mod + mod) % mod;
        cout << t1 << endl;
    }    
}