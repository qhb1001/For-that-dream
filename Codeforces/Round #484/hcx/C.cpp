#include <iostream>
#include <vector>
using namespace std;
const int maxn=2e5+10;
int son[maxn];
vector<int>root[maxn];
int n,ans=0;
void dfs(int now,int pre){
    son[now]=1;
    int m=root[now].size();
    for(int i=0;i<m;i++){
        if(root[now][i]!=pre){
            dfs(root[now][i], now);
            son[now]=son[now]+son[root[now][i]];
            if(son[root[now][i]]%2==0) ans++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        root[u].push_back(v);
        root[v].push_back(u);
    }
    dfs(1, 0);
    if(son[1]%2!=0){
        cout<<-1<<endl;
    }else cout<<ans<<endl;
    return 0;
}
