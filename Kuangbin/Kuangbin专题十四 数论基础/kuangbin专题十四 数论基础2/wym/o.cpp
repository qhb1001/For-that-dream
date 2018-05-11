#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn = 4e6+5;
int N;
int phi[maxn];
ll sum[maxn],ans[maxn];

void init(int x){
    for(int i=1; i<x; i++) phi[i]=i;
    for(int i=2; i<x; i++){
        if(phi[i]<i) continue;
        for(int j=i; j<x; j+=i) phi[j]=phi[j]/i*(i-1);
    }
}

int main(){
    init(maxn);
    for(int i=1; i<maxn; i++) 
        for(int j=i*2; j<maxn; j+=i)
            sum[j]+=(ll)i*phi[j/i];
    ans[2]=sum[2];
    for(int i=3; i<maxn; i++) 
        ans[i]=ans[i-1]+sum[i];
    while(~scanf("%d", &N) && N){
        printf("%lld\n", ans[N]);
    }
    return 0;
}
