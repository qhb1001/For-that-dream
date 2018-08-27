//wa 1times 原因是b应该用long long
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Node{
    ll p,c;
    bool operator<(const Node& o)const{
        return p<o.p;
    }
}chocolate[maxn];
int n;
ll ans=0,x,b;
int main(){
    scanf("%d%lld",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&chocolate[i].p,&chocolate[i].c);
    }
    sort(chocolate+1,chocolate+1+n);
    for(int i=1;i<=n;i++){
        x=b/chocolate[i].p;
        if(x==0) break;
        x=min(x,chocolate[i].c);
        ans+=x;
        b-=x*chocolate[i].p;
    }
    printf("%lld\n",ans);
    return 0;
}