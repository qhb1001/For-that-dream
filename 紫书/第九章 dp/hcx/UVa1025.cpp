#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=1e6;
bool has_Train[255][65][2];
int t[65];
int dp[255][65];
int n,T,M1,M2,kase=0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        if(!n) break;
        cin>>T;
        memset(has_Train,0,sizeof(has_Train));
        for(int i=1;i<n;i++){
            cin>>t[i];
        }
        cin>>M1;
        for(int i=0;i<M1;i++){
            int x;cin>>x;
            has_Train[x][1][0]=1;
            for(int j=1;j<n;j++){
                x+=t[j];
                if(x>T) break;
                has_Train[x][j+1][0]=1;
            }
        }
        cin>>M2;
        for(int i=0;i<M2;i++){
            int x;cin>>x;
            has_Train[x][n][1]=1;
            for(int j=n-1;j>=1;j--){
                x+=t[j];
                if(x>T) break;//Runtime error!!!
                has_Train[x][j][1]=1;
            }
        }
        
        for(int i=1;i<=n-1;i++)
            dp[T][i]=INF;
        dp[T][n]=0;
//        for(int i=0;i<=T;i++){
//            for(int j=1;j<=n;j++){
//                cout<<i<<" "<<j<<" "<<has_Train[i][j][0]<<" "<<has_Train[i][j][1]<<endl;
//            }
//        }
        for(int i=T-1;i>=0;i--){
            for(int j=1;j<=n;j++){
//                cout<<i<<" "<<j<<" "<<has_Train[i][j][0]<<" "<<has_Train[i][j][1]<<endl;
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&has_Train[i][j][0]&&i+t[j]<=T){
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
//                    cout<<i+t[j]<<" "<<dp[i][j]<<endl;
                }
                if(j>1&&has_Train[i][j][1]&&i+t[j-1]<=T){
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
//                    cout<<i+t[j-1]<<" "<<dp[i][j]<<endl;
                }
//                cout<<dp[i][j]<<endl;
            }
        }
        
        cout<<"Case Number "<<++kase<<": ";
        if(dp[0][1]>=INF) cout<<"impossible\n";
        else cout<<dp[0][1]<<"\n";
    }
    return 0;
}
