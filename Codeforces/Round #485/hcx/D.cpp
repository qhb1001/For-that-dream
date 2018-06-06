#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int maxx=105;
int dp[maxn][maxx];
queue<int>q;
vector<int>Edge[maxn];
int a[maxn];
int n,m,k,s,u,v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m>>k>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++){
        cin>>u>>v;
//        cout<<u<<" "<<v<<endl;
        Edge[u].push_back(v);
        Edge[v].push_back(u);
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==i){
                q.push(j);
                dp[j][i]=1;
//                cout<<j<<" . "<<i<<endl;
            }
        }
        while(!q.empty()){
            int now=q.front();
            q.pop();
//            cout<<"now: "<<now<<endl;
            int len=Edge[now].size();
            for(int l=0;l<len;l++){
//                cout<<" *it "<<Edge[now][l]<<endl;
                if(dp[Edge[now][l]][i]==0){
                    dp[Edge[now][l]][i]=dp[now][i]+1;
                    q.push(Edge[now][l]);
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        int ans=0;
        sort(dp[i]+1, dp[i]+1+k);
        for(int j=1;j<=s;j++){
            ans+=dp[i][j]-1;
        }
        if(i==1) cout<<ans;
        else cout<<" "<<ans;
    }
    cout<<endl;
    return 0;
}
