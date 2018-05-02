#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5;
string s;
int n,r,l;
ll dp[maxn][maxn];
int val[maxn],ID[maxn];
void cal(){
    l=0;r=0;
    for(int i=n-1;i>=0;i--){
        if(s[i]==')') ID[i]=++r;
        else{
            ID[i]=++l;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(s[i]=='(') continue;
        ll x=val[i+1];
        int pos=i-1;
        while(pos>=0){
            if(s[pos]=='('){
                dp[ID[pos]][ID[i]] = val[pos+1]*x;
            }
            else{
                x+=val[pos+1];
            }
            pos--;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        cin>>s;
        for(int i=1;i<=n;i++){
            cin>>val[i];
        }
        cal();
        ll sum=0;
        //cout<<l<<" "<<r<<endl;
        for(int i=1;i<=l;i++){
            for(int j=1;j<=r;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j];
                if(j!=1) dp[i][j]=max(dp[i][j],dp[i][j-1]);
                sum=max(sum,dp[i][j]);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
