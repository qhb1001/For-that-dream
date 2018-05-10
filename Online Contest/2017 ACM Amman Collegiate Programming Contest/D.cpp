#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
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
    ll x,y,d=extgcd(a,mod,x,y);
    x=(x%mod+mod)%mod;
    return x;
}
ll fac[200005];

long long fun(ll a,ll b){
    ll x=inv((1LL*fac[b]*fac[a-b])%mod);
    return (1LL*fac[a]*x)%mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
    int T;cin>>T;
    while(T--){
        ll a,b;
        cin>>a>>b;
        cout<<(1LL*2*fun(a-1,b)+mod)%mod<<endl;
    }
    return 0;
}
