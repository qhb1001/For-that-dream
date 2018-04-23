#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
int main(){
    int t;
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll ans = n - (int)sqrt(n) -(int)sqrt(n/2);
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}

