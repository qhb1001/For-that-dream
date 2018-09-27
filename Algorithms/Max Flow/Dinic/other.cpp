#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,s,t,cnt,cur[10002],head[10002],num[10002];
int a[10002],fa[10002],Min[10002],d[10002],ans,q[10002],l;
bool f[10002];
typedef struct{
    int flow,cap,nex,to;
}bian;
bian p[200002];
int ch_top=1e7;
char ch[10000000],*now_r=ch;
void add(int u,int v,int w){
    p[cnt].cap=w;p[cnt].to=v;p[cnt].nex=head[u];head[u]=cnt++;
    p[cnt].cap=0;p[cnt].to=u;p[cnt].nex=head[v];head[v]=cnt++;
}
bool bfs(int s){
    memset(d,-1,sizeof(d));
    l=0;int u;
    d[t]=0;q[l++]=t;
    for (int i=0;i<l;i++)
    {
        u=q[i];
        for (int j=head[u];j!=-1;j=p[j].nex)
        if (p[j^1].cap>p[j^1].flow && d[p[j].to]==-1)
        {
            d[p[j].to]=d[u]+1;
            q[l++]=p[j].to;if (p[j].to==s)return true;
        }
    }
    return false;
}
int dfs(){//奇妙的手工递归
    int now=s;a[now]=0;Min[now]=1e9;
    while(1)
    {
        ccj: if (Min[now] && now!=t)
        {
            if (!f[now])f[now]=1;
            else cur[now]=p[cur[now]].nex;
            for (int& i=cur[now];i!=-1;i=p[i].nex)
            if (p[i].cap>p[i].flow && d[p[i].to]+1==d[now])
            {
                num[p[i].to]=i;a[p[i].to]=0;fa[p[i].to]=now;
                Min[p[i].to]=min(Min[now],p[i].cap-p[i].flow);
                now=p[i].to;f[p[i].to]=0;
                goto ccj;
            }
        }
        if (now==s)return a[s];
        if (now==t)a[now]=Min[now];
        if (Min[now] && now!=t)d[now]=-2;
        p[num[now]].flow+=a[now];p[num[now]^1].flow-=a[now];
        a[fa[now]]+=a[now];Min[fa[now]]-=a[now];now=fa[now];
    }
}
int read() 
{ 
int x=0;
  while(*now_r<48)++now_r;
  for (x=*now_r-48;*++now_r>=48;)
   x= (x<<1)+(x<<3)+*now_r-48;
   return x;
}
int main()
{
    fread(ch,1,ch_top,stdin);
    n=read();m=read();s=read();t=read();
    memset(head,-1,sizeof(head));
    int u,v,w;
    for (int i=0;i<m;i++)
    {
        u=read();v=read();w=read();
        add(u,v,w);
    }
    while(bfs(s))
    {
        for (int i=1;i<=n;i++)
        {f[i]=0;cur[i]=head[i];}
        ans+=dfs();
    }
    printf("%d",ans);
    return 0;
}