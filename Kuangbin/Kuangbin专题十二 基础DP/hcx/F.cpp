#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=505;
const int maxx=1e4+5;
const int INF=0x3f3f3f3f;
struct ty{
    int c,w;
}coins[maxn];
bool cmp(ty a,ty b){
    if(a.c==b.c){
        return a.w>b.w;
    }
    return a.c<b.c;
}

ll dp[maxx];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int e,f;scanf("%d%d",&e,&f);
        int m=f-e;
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            cin>>coins[i].w>>coins[i].c;
        }
        if(!m){
            cout<<"The minimum amount of money in the piggy-bank is 0."<<endl;
            continue;
        }
        sort(coins+1,coins+1+n,cmp);
        memset(dp, INF, sizeof(dp));

        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=coins[i].c;j<=m;j++){
//                cout<<coins[i].c<<" "<<j-coins[i].c<<" "<<dp[j-coins[i].c]<<" "<<dp[j]<<" ";
                if(dp[j-coins[i].c]+coins[i].w<dp[j])
                    dp[j]=dp[j-coins[i].c]+coins[i].w;
//                cout<<dp[j]<<endl;
            }
        }
//        cout<<INF<<" "<<dp[m]<<endl;
        if(dp[m]<INF){
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[m]<<"."<<endl;
        }
        else{
            cout<<"This is impossible."<<endl;
        }
    }
    return 0;
}
