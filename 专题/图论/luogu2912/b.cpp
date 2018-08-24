#include<cstdio>
#include<algorithm>
using namespace std;
const int _ = 100005;
int n,to[_],dfn[_],low[_],tot,stack[_],top,vis[_],col[_],scc,out[_],sz[_],dp[_];
int gi()
{
    int x=0,w=1;char ch=getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if (ch=='-') w=0,ch=getchar();
    while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return w?x:-x;
}
void Tarjan(int u)
{
    dfn[u]=low[u]=++tot;
    stack[++top]=u;vis[u]=1;
    int v=to[u];
    if (!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
    else if (vis[v]) low[u]=dfn[v];
    if (dfn[u]==low[u])
    {
        scc++;//强联通分量的标号
        do
        {
            v=stack[top--];
            vis[v]=0;
            col[v]=scc;//某点所在的强联通分量的标号
            sz[scc]++;//大小
        }while (u!=v);
    }
}
int dfs(int u)
{
    if (!u||dp[u]) return dp[u];
    return dp[u]=dfs(out[u])+sz[u];
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output.b", "w",stdout);
    n=gi();
    for (int i=1;i<=n;i++)
        to[i]=gi();
    for (int i=1;i<=n;i++)
        if (!dfn[i]) Tarjan(i);
    for (int i=1;i<=n;i++)
        if (col[i]!=col[to[i]])
            out[col[i]]=col[to[i]];
    for (int i=1;i<=n;i++)
        printf("%d\n",dfs(col[i]));
    return 0;
}