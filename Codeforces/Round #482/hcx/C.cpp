#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=3e5+10;
vector<int>Node[maxn];
ll num[maxn];
bool vis[maxn],mid[maxn];
int n,x,y,u,v;
void dfs(int v,int root){
    num[v]=1;
    int len=Node[v].size();
    for(int i=0;i<len;i++){
        int u=Node[v][i];
        if(u!=root){
            dfs(u, v);
//            cout<<v<<" "<<u<<" ";
            num[v]+=num[u];
//            cout<<num[u]<<" "<<num[v]<<endl;
            if(vis[u]) vis[v]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x>>y;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        Node[u].push_back(v);
        Node[v].push_back(u);
    }
    vis[y]=1;
    dfs(x, 0);//x->...->y
    int len=Node[x].size();
//    cout<<num[x]<<" "<<num[y]<<" ";
    for(int i=0;i<len;i++){
        if(vis[Node[x][i]]) num[x]-=num[Node[x][i]];//减去(i->y的条数-1)剩下的是i->x->y和x->y的条数
    }
//    cout<<num[x]<<endl;
    ll ans=1LL*n*(n-1)-1LL*num[x]*num[y];
    cout<<ans<<endl;
    return 0;
}
