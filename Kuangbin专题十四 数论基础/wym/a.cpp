#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
int prime[maxn] = {1,1,0};
int main(){
    for(int i=2; i<maxn; i++){
        if(!prime[i]){
            for(int j=i+i; j<=maxn; j+=i){
                prime[j] = 1;
            }
        }
    }
    int T, n, kase = 0;
    int m;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ll ans = 0;
        while(n--){
            scanf("%d",&m);
            for(int i=m+1; ; i++){
                if(prime[i] == 0){
                    ans += i;
                    break;
                }
            }
        }
        printf("Case %d: %lld Xukha\n",++kase, ans);
    }
    return 0;
}

