#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
ll a, b;
const int maxn = 1000005;
int flag[maxn];
int prime[maxn];
void getPrime(){
    memset(flag,0,sizeof(flag));
    memset(prime,0,sizeof(prime));
    flag[0] = flag[1] = 1;
    for(int i=2; i<maxn; i++){
        if(!flag[i])    prime[++prime[0]] = i;
        for(int j=1; j<=prime[0] && i*prime[j]<=maxn; j++){
            flag[prime[j] * i] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int solve(){
    if (a/b < b)    return 0;
    int ans = 1;
    ll tmp = a;
    for(int i=1; i<prime[0] && prime[i]*prime[i]<=tmp; i++){
        if(tmp % prime[i] == 0){
            int x = 0;
            while(tmp % prime[i] == 0){
                x++;
                tmp /= prime[i];
            }
            ans *= (x+1);
        }
    }
    if(tmp > 1)   ans *= 2;
    ans /= 2;
    for(int i=1; i<b; i++){
        if(a % i == 0)  ans--;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    int kase = 0;
    getPrime();
    while(t--){
        scanf("%lld%lld",&a,&b);
        ll m = (ll)sqrt((double)a+0.5);
        printf("Case %d: %d\n",++kase, solve());
    }
    return 0;
}

