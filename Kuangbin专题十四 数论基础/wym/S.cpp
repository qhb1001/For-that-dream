#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
 using namespace std;
 typedef long long ll;
 ll A,B,C,k;
 ll a,b,c,d,e,f,x,y;
 ll exgcd(ll a,ll b,ll &x,ll &y){
     if (b==0){
         x=1;
         y=0;
         return a;
     }
     ll res=exgcd(b,a%b,x,y);
     ll tmp=x;
     x=y;
     y=tmp-(a/b)*y;
     return res;
 }
 int main(){
     int i,j;
     while (1){
         scanf("%lld%lld%lld%lld",&A,&B,&C,&k);
         if (A==0 && B==0 && C==0 && k==0)
             break;
         a=C,b=1ll<<k,c=B-A;
         d=exgcd(a,b,x,y);
         if (c==0){
             puts("0");
             continue;
         }
         if (c%d!=0){
             puts("FOREVER");
             continue;
         }
         e=x*(c/d);
         f=(e%(b/d)+b/d)%(b/d);
         printf("%lld\n",f);
     }
     return 0;
 }
