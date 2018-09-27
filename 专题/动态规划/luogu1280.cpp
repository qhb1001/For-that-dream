#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 1<<30
int main(){
    vector<int>q[10005];
    int N,n;
    scanf("%d%d",&N,&n);
    
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        q[a].push_back(b);
    }
    
    int dp[10005] = {0};
    for(int i=N;i>=1;i--)
        if(q[i].size()==0)  dp[i]=dp[i+1];
        else{
            int x=INF;
            for(int j=0;j<q[i].size();j++){
                int end=i+q[i][j];
                x=min(x,dp[end]+q[i][j]);
            }
            dp[i]=x;
        }
    
    cout<<N-dp[1]<<endl;
}