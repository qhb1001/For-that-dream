#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1005;
struct ty{
    int w,s,idx;
}mice[maxn];
bool cmp(ty a,ty b){
    if(a.w==b.w){
        if(a.s==b.s){
            return a.idx<b.idx;
        }
        return a.s>b.s;
    }
    return a.w<b.w;
}
int dp[maxn],pre[maxn];
int ans[maxn];
int main(){
    int n=1;
    while(scanf("%d%d",&mice[n].w,&mice[n].s)!=EOF){
//        if(!mice[n].w) break;
        mice[n].idx=n;
        n++;
    }
    sort(mice+1,mice+n,cmp);
    dp[1]=1;pre[1]=-1;
    for(int i=2;i<n;i++){
        int v=-1,idx=1;
        for(int j=1;j<i;j++){
            if(v<dp[j]&&mice[j].w<mice[i].w&&mice[j].s>mice[i].s){
                v=dp[j];
                idx=j;
            }
        }
        if(v==-1){
            dp[i]=1;
            pre[i]=-1;
        }
        else{
            dp[i]=v+1;
            pre[i]=idx;
        }
//        cout<<mice[i].idx<<" "<<dp[i]<<" "<<pre[i]<<" ";
//        if(pre[i]!=-1){
//            cout<<mice[pre[i]].idx;
//        }
//        cout<<endl;
    }

    int idx=1;
    for(int i=2;i<n;i++){
        if(dp[i]>dp[idx]) idx=i;
    }

    printf("%d\n",dp[idx]);

    int num=0;
    while(pre[idx]!=-1){
        ans[num]=mice[idx].idx;
        num++;
        idx=pre[idx];
    }
    ans[num]=mice[idx].idx;
    for(int i=num;i>=0;i--){
        printf("%d\n",ans[i]);
    }
    return 0;
}
