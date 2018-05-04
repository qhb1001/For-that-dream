#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
bool vis[maxn];
vector<pair<int,int> >Edge[maxn];

void init(){
    memset(vis, 0, sizeof(vis));
    for(int i=0;i<maxn;i++) Edge[i].clear();
}

//start from 1
ll prim(){
    ll res=0;
    priority_queue<pair<int,int> >q;
    for(int i=0;i<Edge[1].size();i++){
        int u=Edge[1][i].first;
        int d=Edge[1][i].second;
        q.push(make_pair(d, u));
    }
    vis[1]=1;
    while(!q.empty()){
        int now=q.top().second;
        int d=q.top().first;
        q.pop();
        if(vis[now]) continue;
        vis[now]=1;
        res=res+(d);
        for(int i=0;i<Edge[now].size();i++){
            int u=Edge[now][i].first;
            int d=Edge[now][i].second;
            q.push(make_pair(d,u));
        }
    }
    return res;
}

int main(){
    //when add edge, you should update both Edge[u] and Edge[v];
    return 0;
}
