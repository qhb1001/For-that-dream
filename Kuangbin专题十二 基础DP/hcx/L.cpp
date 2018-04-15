#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1005;
int dp[maxn][maxn];
int main(){
    string a,b;
    int na,nb;
    while(cin>>a>>b){
        na=a.length();nb=b.length();
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=na;i++){
            for(int j=1;j<=nb;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[na][nb]<<endl;
    }
    return 0;
}
