#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAXN_ 5050
#define INF 0x3f3f3f3f
#define P pair<int,int>
using namespace std;
struct edge{ int to,cap,cost,rev;};
int n,m,flow,s,t,cap,res,cost,from,to,h[MAXN_];
std::vector<edge> G[MAXN_];
int dist[MAXN_],prevv[MAXN_],preve[MAXN_]; // 前驱节点和对应边
inline void add()
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
} // 在vector 之中找到边的位置所在!
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9'){if(c=='-')flag=1;    c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?-x:x;
}
inline void min_cost_flow(int s,int t,int f)
{
    fill(h+1,h+1+n,0);
    while(f > 0)
    {
        priority_queue<P,vector<P>, greater<P> > D;
        memset(dist,INF,sizeof dist);
        dist[s] = 0; D.push(P(0,s));
        while(!D.empty())
        {
            P now = D.top(); D.pop();
            if(dist[now.second] < now.first) continue;
            int v = now.second;
            for(int i=0;i<(int)G[v].size();++i)
            {
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    D.push(P(dist[e.to],e.to));
                }
            }
        }
        // 无法增广 ， 就是找到了答案了！
        if(dist[t] == INF) break;
        for(int i=1;i<=n;++i) h[i] += dist[i]; 
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d,G[prevv[v]][preve[v]].cap);
        f -= d; flow += d;
        res += d * h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
}
int main(int argc,char const* argv[])
{
   n = read(); m = read(); s = read(); t = read();
   for(int i=1;i<=m;++i)
   {
           from = read(); to = read(); cap = read(); cost = read();
           add();
   }
   min_cost_flow(s,t,INF);
   printf("%d %d\n",flow,res);
   return 0;
}