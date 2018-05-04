#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll MAX = 1e6 + 6;
ll sum, last;
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
         sum = 0;
         scanf("%lld", &last);
         last %= MOD;
         sum = last + 1;
         for(int i = 2; i <= n; ++i) {
                 scanf("%lld", &last);
                 last %= MOD;
                 sum = (sum + sum * last) % MOD;  
         }            
         printf("%lld\n", (sum + MOD) % MOD);
    }
}

