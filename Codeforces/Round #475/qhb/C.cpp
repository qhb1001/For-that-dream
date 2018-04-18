#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 9;
ll extgcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b!=0){
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else    x=1,y=0;
    return d;
}
ll inv(ll a){
    ll x,y,d=extgcd(a,MOD,x,y);
    x=(x%MOD+MOD)%MOD;
    return x;
}
ll quick(ll m, ll a) {
	ll ans = 1;
	while(m) {
		if(m&1)	ans = ((ans * a) % MOD + MOD) % MOD;
		a = (a * a) % MOD;
		m >>= 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b, k, base = 0, sum = 0, base_ = 1;
	cin >> n >> a >> b >> k;
	string in;
	cin >> in;

	for(int i = 0; i < k; ++i) {
		if(in[i] == '-') base = (base - (quick(n - i, a) * quick(i, b)) % MOD + MOD) % MOD;
		else	base = (base + (quick(n - i, a) * quick(i, b)) % MOD + MOD) % MOD;
	}

	
	ll q = ((((inv(quick(k, a))) % MOD) * quick(k, b)) % MOD + MOD) % MOD;
	sum = ((base * (quick((n + 1) / k, q) - 1 + MOD) + MOD) % MOD) * inv(q - 1) % MOD;
	cout << (sum + MOD) % MOD << endl;
}
