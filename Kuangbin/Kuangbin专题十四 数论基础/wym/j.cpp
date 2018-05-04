#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
bool isprime[maxn];
int prime[maxn];
int t = 0;
void getPrime(){
    t = 0;
    memset(isprime,true,sizeof(isprime));
    prime[0] = prime[1] = false;
    for(ll i=2; i<maxn; i++){
        if(isprime[i]){
            prime[t++] = i;
            for(ll j=i*i; j<maxn; j+=i)
                isprime[j] = false;
        }
    }
}
int gcd(int a, int b){
    if(!b)  return a;
    return gcd(b,a%b);
}
int main(){
    int T;
    scanf("%d",&T);
    int kase = 0;
    getPrime();
    ll n;
    while(T--){
        scanf("%lld",&n);
        int flag = 0;
        if(n<0){
            n = -n;
            flag = 1;
        }
        int ans = 0;
        int x;
        for(int i=0; i<t && prime[i]*prime[i]<=n; i++){
            if(n%prime[i] == 0){
                x = 0;
                while(n%prime[i] == 0){
                    x++;
                    n /= prime[i];
                }
                if(!ans)    ans = x;
                else        ans = gcd(ans,x);
            }
        }
        if(n>1){
            ans = gcd(ans,1);
        }
        if(flag){
            while(ans%2==0){
                ans /= 2;
            }
        }
        printf("Case %d: %d\n",++kase, ans);
    }
    return 0;
}
