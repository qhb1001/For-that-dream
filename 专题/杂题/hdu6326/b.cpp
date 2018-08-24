#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=200005;
struct node{
    int id,ti;
    ll a,b;
    bool operator < (const node &o)const
    {
        int d1=o.a<o.b,d2=a<b;
        if(d1!=d2) return d1>d2;//第一步分类
        if(d1>0) return o.a<a;
        return o.b>b;//第二步分类
    }
};
priority_queue<node>q;
node a[maxn];
int n,m,t;
vector<int>g[maxn];
int fa[maxn],f[maxn],vis[maxn];
 
int init()
{
    while(!q.empty())q.pop();
    for(int i=0;i<=n;i++)
    {
        g[i].clear();
        a[i].a=a[i].b=0;
        a[i].id=a[i].ti=0;
        fa[i]=0;
        f[i]=i;
        vis[i]=0;
    }
}
void dfs(int u,int pre)
{
    fa[u]=pre;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==pre) continue;
        dfs(v,u);
    }
}
int getfa(int x)
{
    return f[x]==x?x:f[x]=getfa(f[x]);
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.b", "w", stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init();
        for(int i=2;i<=n;i++)
        {
            scanf("%lld%lld",&a[i].a,&a[i].b);
            a[i].id=i;
            a[i].ti=0;
            q.push(a[i]);
        }
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
        int tim=0,x;
        node t,tt;
        while(!q.empty())
        {
            t=q.top();
            q.pop();
            x=t.id;
            if(vis[x]!=t.ti||x==0)continue;
            int y=getfa(fa[x]);
            f[x]=y;
            vis[y]=++tim;
            a[y].a+=max(0ll,-a[y].b+a[x].a);//合并后新的a
            a[y].b=a[x].b+max(0ll,a[y].b-a[x].a);//合并后新的b
            tt.a=a[y].a;
            tt.b=a[y].b;
            tt.ti=vis[y];
            tt.id=y;
            q.push(tt);
       }
        printf("%lld\n",a[0].a);
    }
    return 0;
}
