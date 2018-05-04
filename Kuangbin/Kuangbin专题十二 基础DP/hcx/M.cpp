#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=20005;
const int maxx=1005;
const int INF=1e9+5;
const int inf=0x3f3f3f3f;
int dp[maxn][2];
struct Node{
    int l,r,h;
}pt[maxx];
bool cmp(Node a,Node b){
    return a.h>b.h;
}
int main(){
    int t,n,x,h,MAX;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&x,&h,&MAX);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&pt[i].l,&pt[i].r,&pt[i].h);
        }
        sort(pt+1, pt+1+n, cmp);
        n++;

        int i=1,j;
        while(i<n&&(x<pt[i].l||x>pt[i].r)){
            i++;
        }
        if(i==n){
            cout<<h<<endl;
            continue;
        }
        int ans=INF;
        memset(dp,inf,sizeof(dp));
        dp[i][0]=dp[i][1]=h-pt[i].h;
        dp[i][0]+=x-pt[i].l;
        dp[i][1]+=pt[i].r-x;
//        cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
        for(;i<n;i++){
            if(dp[i][0]<inf){
                for(j=i+1;j<=n;j++){
                    if(pt[i].h-pt[j].h>MAX){
                        break;
                    }
                    if(j==n){
                        ans=min(ans,dp[i][0]+pt[i].h);
                        break;
                    }
                    if(pt[i].l<pt[j].l||pt[i].l>pt[j].r) continue;

                    dp[j][0]=min(dp[j][0],dp[i][0]+pt[i].h-pt[j].h+pt[i].l-pt[j].l);
                    dp[j][1]=min(dp[j][1],dp[i][0]+pt[i].h-pt[j].h+pt[j].r-pt[i].l);
                    //                cout<<"left "<<i<<" -> "<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
                    break;
                }
            }

            if(dp[i][1]<inf){
                for(j=i+1;j<=n;j++){
                    if(pt[i].h-pt[j].h>MAX){
                        break;
                    }
                    if(j==n){
                        ans=min(ans,dp[i][1]+pt[i].h);
                        break;
                    }
                    if(pt[i].r<pt[j].l||pt[i].r>pt[j].r) continue;


                    dp[j][0]=min(dp[j][0],dp[i][1]+pt[i].h-pt[j].h+pt[i].r-pt[j].l);
                    dp[j][1]=min(dp[j][1],dp[i][1]+pt[i].h-pt[j].h+pt[j].r-pt[i].r);
                    //                cout<<"right "<<i<<" -> "<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

