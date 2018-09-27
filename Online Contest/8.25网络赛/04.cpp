#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ll n, a;
		scanf("%lld%lld",&n,&a);
		if(n > 2)
			printf("-1 -1\n");
		else if(n == 0)
			printf("-1 -1\n");
		else if(n == 1)
			printf("1 %lld\n",a+1); 
		else{
			int flag = 0;
			ll tmp = a*a;
			for(ll i=1; i<a; i++){
				if(tmp % i == 0){
					ll yu = tmp / i;
					ll imax = yu;
					ll imin = i;
					ll cha = imax - imin;
					if(cha % 2 == 0){
						flag = 1;
						ll b = (imax - imin) / 2;
						ll c = imax - b;
						printf("%lld %lld\n",b, c);
						break;
					}
				}
			}
			if(flag == 0)
				printf("-1 -1\n");
		} 
	}
	return 0;
} 