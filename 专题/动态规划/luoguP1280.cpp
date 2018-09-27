#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=10100;
struct Task{
    int begin,keep;
    bool operator<(const Task& o)const{
        return begin>o.begin;
    }
}task[maxn];
int n,k;
int dp[maxn];
int main(){
    // freopen("/Users/mrs_empress/Desktop/testdata.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d%d",&task[i].begin,&task[i].keep);
    }
    sort(task+1,task+1+k);
    dp[n+1]=0;
    int pos=1;
    for(int i=n;i>=1;i--){
        if(pos>k){
            dp[i]=dp[i+1]+1;
            continue;
        }
        if(i!=task[pos].begin){
            dp[i]=dp[i+1]+1;
            continue;
        }
        while(pos<=k&&i==task[pos].begin){
            dp[i]=max(dp[i],dp[i+task[pos].keep]);
            pos++;
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}