#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const ll N=1400000;
int pr[N/5],p[N+100],tot;
int fac[N+10],inv[N+10],fnv[N+10];
int _,c,n,k;
ll mul(ll a,ll b) { return (a%mod)*(b%mod)%mod;}
void init() {
    p[1]=1;
    rep(i,2,N+1) {
        if (!p[i]) p[i]=i,pr[++tot]=i;
        for (int j=1;j<=tot&&pr[j]*i<=N;j++) {
            p[i*pr[j]]=pr[j];
            if (p[i]==pr[j]) break;
        }
    }
}
ll comb(int a,int b) {
    return (ll)fac[a]*fnv[b]%mod*fnv[a-b]%mod;
}
ll ff(int p,int k) {
    ll w=0;
    rep(i,0,p) w=(w+comb(i+k-1,k-1)*(p-i))%mod;
    return w;
}

int main() {
    inv[1]=1;
    fac[0]=fnv[0]=1;
    for (int i=2;i<=N;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
    for (int i=1;i<=N;i++) {
        fac[i]=(ll)fac[i-1]*i%mod;
        fnv[i]=(ll)fnv[i-1]*inv[i]%mod;
    }
    init();

    for (scanf("%d",&_);_;_--) {
        scanf("%d%d%d",&c,&n,&k);
        int p=pr[c];
        ll ans=0;
        rep(i,1,k+1) {
            ll base=((p+i)*comb(p-1+i,i)-i*comb(p+i,i+1))%mod;
            if(base<0) base+=mod;
            if (base==1) {
                ans=(ans+n)%mod;
            } else if (base>0) {
                ll a=powmod(base,n)-1;
                ll b=powmod(base-1,mod-2);
                a=a*b%mod; a=a*base%mod;
                ans=(ans+a)%mod;
            }
        }
        printf("%lld\n",ans);
    }
}