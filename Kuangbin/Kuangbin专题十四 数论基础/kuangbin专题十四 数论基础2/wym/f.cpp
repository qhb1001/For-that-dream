#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn = 1e7 + 5;
int prime[700000];
int flag[maxn];
void init(){
    for(int i=0; i<maxn; i++)   flag[i] = 1;
    flag[0] = flag[1] = 0;
    int t = 0;
    for(int i=2; i<maxn; i++){
        if(flag[i]){
            prime[t++]  = i;
            for(int j=i+i; j<maxn; j+=i)    flag[j] = 0;
        }
    }
}
int main(){
    init();
    int t;
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        int n;
        int ans = 0;
        scanf("%d",&n);
        for(int i=0; prime[i]+prime[i]<=n; i++){
            if(flag[n-prime[i]])    ans++;
        }
        printf("Case %d: %d\n",++kase,ans);
    }
    return 0;
}
