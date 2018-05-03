#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 50000;
int vis[maxn], isprime[5500], num[100005], k;
void prime(){
    long long i, j;
    for (k=0,i=2; i<maxn; i++)
        if (vis[i] == 0){
            isprime[k ++] = i;
            for (j=i*i; j<maxn; j+=i)
                vis[j] = 1;
        }
}

int main (){
    int t, kase = 0;
    prime ();
    scanf ("%d", &t);
    while (t --){
        int a, b, ans = 0;
        int n;
        scanf ("%d %d", &a, &b);
        n = b - a;
        memset (num, 0, sizeof(num));
        for (int i=0; isprime[i] <= (int)sqrt(b) && i<k; i++){
            int j = 0;
            if (a % isprime[i] != 0 )
                j = j - a % isprime[i] + isprime[i];
            if (a <= isprime[i])
                j += isprime[i];
            for ( ; j<=n; j+=isprime[i]){
                    num[j] = 1;
            }
        }
        for (int i=0; i<=n; i++)
            if (!num[i])
                ans ++;
        if (a == 1)
            ans --;
        printf ("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
