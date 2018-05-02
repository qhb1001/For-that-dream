#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
queue<ll>p;
int main(){
    int n;ll d;
    scanf("%d%lld",&n,&d);
    ll bef,now,x;
    if(n==1||n==2){
        while(n--) scanf("%lld",&now);
        printf("0\n");
        return 0;
    }

    if(n==3){
        scanf("%lld%lld%lld",&bef,&x,&now);
        if(now-bef<=d) printf("1\n");
        else printf("0\n");
        return 0;
    }

    scanf("%lld%lld",&x,&bef);
    p.push(x);
    ll sum=0,cnt=1;
    for(int i=3;i<=n;i++){
        scanf("%lld",&now);
        if(cnt!=0){
            ll x=p.front();
            while((now-x)>d){
                p.pop();
                cnt--;
                if(cnt==0) break;
                x=p.front();
            }
        }
        sum+=cnt+cnt*(cnt-1)/2;
        p.push(bef);
        bef=now;
        cnt++;
    }
    printf("%lld\n",sum);
    return 0;
}
