#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
ll mod=1e9+9;
ll d,a0;
ll mypow(ll a, ll b){
    ll ans = 1, base = a;
    while(b!=0){
        if(b & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}

int main(){
    ll n,a,b,k;
    scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
    string s;cin>>s;
    a0=0;
    for(int i=0;i<k;i++){
        if(s[i]=='+'){
            a0=(a0+mypow(a, n-i)*mypow(b, i)%mod)%mod;
        }
        else{
            a0=(a0-mypow(a, n-i)*mypow(b, i)%mod)%mod;
        }
        a0=(a0+mod)%mod;
    }
//    cout<<a0<<endl;
    d=(mypow(b, k)*mypow(a, k*(mod-2LL)%(mod-1LL))+mod)%mod;
    if(d==1) cout<<(((a0*((n+1)/k)%mod)+mod)%mod)<<endl;
    else cout<<(((a0*(mypow(d,(n+1)/k)-1)+mod)%mod*mypow(d-1,mod-2)%mod)+mod)%mod<<endl;
    return 0;
}

