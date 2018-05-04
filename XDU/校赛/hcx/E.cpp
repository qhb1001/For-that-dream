#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
ll dp[3];
int main(){
    string s;
    while(cin>>s){
        ll n=s.length();
        ll ans=0;
        dp[0]=dp[1]=dp[2]=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ll tmp=dp[0];
                dp[0]=dp[1];
                dp[2]=dp[2];
                dp[1]=tmp+1;
            }
            else{
                ll tmp=dp[1];
                dp[1]=dp[2];
                dp[2]=tmp;
                dp[0]=dp[0]+1;
            }
            ans+=dp[0];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
