#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int flag[maxn+5];
int prime[maxn+5];
int count = 0;
int ans = 0;
void getPrime(){
    for(int i=2; i<maxn; i++){
        if(flag[i]) continue;
        prime[count++] = 1;
        for(int j=i*i; j<maxn; j+=i)
            flag[j] = 1;
    }
}
void deal(){
    for(int i=0; )
}
int main(){
    int t;
    while(t--){
        ll n;
        scanf("%lld",&n);

    }
}
