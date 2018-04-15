#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=200;
const int INF=0x3f3f3f3f;
struct ty{
    ll x,y,z;
}rec[maxn];
bool cmp(ty a,ty b){
    if(a.y==b.y){
        return a.x>b.x;
    }
    return a.y>b.y;
}
ll dp[maxn];
int main(){
    int Case=0;
    int n,num;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        num=1;
        for(int i=1;i<=n;i++){
            ll xx,yy,zz;
            scanf("%lld%lld%lld",&xx,&yy,&zz);
            if(xx>yy) swap(xx, yy);
            if(xx>zz) swap(xx,zz);
            if(yy>zz) swap(yy, zz);
            rec[num].x=xx;rec[num].y=yy;rec[num].z=zz;
            num++;
            rec[num].x=xx;rec[num].y=zz;rec[num].z=yy;
            num++;
            rec[num].x=yy;rec[num].y=zz;rec[num].z=xx;
            num++;
        }
        sort(rec+1,rec+num+1,cmp);
        dp[0]=0;
        for(int i=1;i<num;i++){
            ll v=0;
            for(int j=1;j<i;j++){
                if(rec[j].x<=rec[i].x||rec[j].y<=rec[i].y)
                    continue;
                v=max(v,dp[j]);
            }
            dp[i]=v+rec[i].z;
//            cout<<i<<" "<<dp[i]<<" "<<v<<endl;
        }
        ll ans=-1;
        for(int i=1;i<num;i++){
            ans=max(dp[i],ans);
        }
        cout<<"Case "<<++Case<<": maximum height = "<<ans<<endl;
    }
    return 0;
}
