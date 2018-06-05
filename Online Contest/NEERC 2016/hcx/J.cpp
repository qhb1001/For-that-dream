#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e4+10;
vector<int>G[maxn];
char num[maxn][10];
int Link[maxn],vis[maxn];
int n,m,ans;

bool Find(int u){
    int len=G[u].size();
    for(int i=0;i<len;i++){
        int v=G[u][i];
        if(vis[v]) continue;
        vis[v]=true;
        if(Link[v]==-1||Find(Link[v])){
            Link[v]=u;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
//        cout<<num[i]<<endl;
    }
    
    for(int i=1;i<=m;i++){
        cin>>num[i+n];
//        cout<<num[i+n]<<endl;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(num[i][0]+num[i][1]+num[i][2]==num[j+n][3]+num[j+n][4]+num[j+n][5])
                G[i].push_back(j+n);
            if(num[i][3]+num[i][4]+num[i][5]==num[j+n][0]+num[j+n][1]+num[j+n][2])
                G[i].push_back(j+n);
        }
    }
    
    ans=0;
    memset(Link,-1,sizeof(Link));
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(Find(i)) ans++;
    }
    cout<<ans<<endl;
    
    for(int i=n+1;i<=n+m;i++){
        if(Link[i]==-1) continue;
        if(num[Link[i]][0]+num[Link[i]][1]+num[Link[i]][2]==num[i][3]+num[i][4]+num[i][5])
            cout<<"AT"<<" "<<num[Link[i]]<<" "<<num[i]<<endl;
        else if(num[i][0]+num[i][1]+num[i][2]==num[Link[i]][3]+num[Link[i]][4]+num[Link[i]][5])
        cout<<"TA"<<" "<<num[i]<<" "<<num[Link[i]]<<endl;
    }
    return 0;
}

