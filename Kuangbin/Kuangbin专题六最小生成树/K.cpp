#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int maxn=110;
const int INF=0x3f3f3f3f;
bool vis[maxn];
int pre[maxn];
int Maxlen[maxn][maxn];
int mmap[maxn][maxn];
bool used[maxn][maxn];
int d[maxn];
int n,m;
int prim(){
    int ans=0;
    memset(vis,0,sizeof(vis));
    memset(Maxlen,0,sizeof(Maxlen));
    memset(used, 0, sizeof(used));
    vis[1]=1;
    pre[0]=-1;
    for(int i=2;i<=n;i++){
        d[i]=mmap[1][i];
        pre[i]=1;
    }
    d[0]=0;
    
    for(int i=2;i<=n;i++){
        int minn=INF;
        int v=-1;
        for(int j=2;j<=n;j++){
            if(!vis[j]&&minn>d[j]){
                minn=d[j];
                v=j;
            }
        }
        if(minn==INF){
            return -1;
        }
        
        ans+=minn;
        vis[v]=1;
        used[v][pre[v]]=used[pre[v]][v]=1;
        
        for(int j=1;j<=n;j++){
            if(vis[j]) Maxlen[j][v]=max(Maxlen[j][pre[v]],d[v]);
            if(!vis[j]&&d[j]>mmap[v][j]){
                d[j]=mmap[v][j];
                pre[j]=v;
            }
        }
    }
    return ans;
}

void work(int ans){
    int minn=INF;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mmap[i][j]!=INF&&!used[i][j]){
                minn=min(minn,ans+mmap[i][j]-Maxlen[i][j]);
            }
        }
    }
    if(minn==ans) printf("Not Unique!\n");
    else printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) mmap[i][j]=0;
                else mmap[i][j]=INF;
            }
        }
        int u,v,w;
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            mmap[u][v]=mmap[v][u]=w;
        }
        int ans=prim();
        if(ans==-1){
            printf("Not Unique!\n");
            continue;
        }
        work(ans);
    }
    return 0;
}
