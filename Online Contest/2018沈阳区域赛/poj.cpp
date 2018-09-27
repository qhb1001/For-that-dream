#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define Maxn 10010
#define INF 1000000000
 
struct node{
	int to,val;
	node() {}
	node(int a,int b)
	{
		to = a; val = b;
	}
};
 
vector<node> adj[Maxn],_adj[Maxn];
 
int n,m,k;
bool vis[Maxn];
int dis[Maxn];
 
void AddEdge(int x,int y,int val)
{
	adj[x].push_back(node(y,val));
	_adj[y].push_back(node(x,val));//把图反向
}
void Dijkstra(int s,int t)
{
	priority_queue<int , vector<int> , greater<int> > q;
	while(!q.empty()) q.pop();
	
	for(int i=1;i<=n;i++) vis[i] = false,dis[i] = INF;
	vis[t] = true; dis[t] = 0; q.push(t);
	
	int u,len;
	while(!q.empty())
	{
		u = q.top();  q.pop();
		len = _adj[u].size();
		for(int i=0;i<len;i++)
		{
			node v = _adj[u][i];
			if(dis[v.to] > dis[u] + v.val)
			{
				dis[v.to] = dis[u] + v.val;
				if(!vis[v.to])
				{
					q.push(v.to);
					vis[v.to] = true;
				}
			}
		}
		vis[u] = false;
	}
}
 
struct Anode{
	int h,g,id;
	Anode(int a,int b,int c) {h=a; g=b; id=c;}
	bool operator < (Anode a) const
	{
		return h+g > a.h+a.g;
	}
};
 
priority_queue<Anode> Q;
 
int Astar(int s,int t)//A*算法过程
{
	while(!Q.empty()) Q.pop();
	Q.push(Anode(0,dis[s],s));
	
	int len,num;
	num = 0;
	while(!Q.empty())
	{
		Anode u = Q.top(); Q.pop();
		if(u.id==t) ++num;
		if(num>=k) return u.h;
		
		len = adj[u.id].size();
		for(int i=0;i<len;i++)
		{
			node v = adj[u.id][i];
			Q.push(Anode(u.h+v.val,dis[v.to],v.to));
		}
	}
	
	return -1;//不能连通或者没有第K短路
}
 
int main()
{
	while(scanf("%d%d",&n,&m)!=-1)
	{
		for(int i=0;i<Maxn;i++) adj[i].clear(),_adj[i].clear();
		int x,y,v,s,t;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&v);
			AddEdge(x,y,v);
		}
		scanf("%d%d%d",&s,&t,&k);
		if(s==t) k++;
		Dijkstra(s,t);
		printf("%d\n",Astar(s,t));

        for (int i = 1; i <= n; ++i) cout << dis[i] << ' ';
        cout << endl;
        
	}
	return 0;
}

