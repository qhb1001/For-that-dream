#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5+10;
vector<pair<int,int> >E[N];
int n,m;
int d[N];
bool vis[N];

void Init(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<N;i++) d[i]=INF;
    for(int i=0;i<N;i++) E[i].clear();
}

void Dijkstra(int s){
    priority_queue<pair<int,int> >Q;
    d[s]=0;
    Q.push(make_pair(-d[s], s));

    while(!Q.empty()){
        int now=Q.top().second;
        Q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        for(int i=0;i<E[now].size();i++){
            int v=E[now][i].first;
            int D=d[now]+E[now][i].second;
            if(d[v]>D){
                d[v]=D;
                Q.push(make_pair(-d[v], v));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    Init();
    for(int i=0;i<m;i++){
        int x,y,d;cin>>x>>y>>d;
        E[x].push_back(make_pair(y,d));
        E[y].push_back(make_pair(x,d));
    }
    Dijkstra(1);
    cout<<d[n]<<endl;
    return 0;
}

