#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll cal(ll n){
    ll sum = 0;
    while(n){
        sum += n/5;
        n /= 5;
    }
    return sum;
}
int main(){
    int t;
    scanf("%d",&t);
    int kase = 0;
    while(t--){
        int q;
        scanf("%d",&q);
        ll left = 4, right = 500000000;
        while(left <= right){
            ll mid = (left + right) >> 1;
            ll m = cal(mid);
            if(m < q){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(cal(left) == q){
            printf("Case %d: %lld\n",++kase,left);
        }
        else{
            printf("Case %d: impossible\n",++kase);
        }
    }
    return 0;
}
