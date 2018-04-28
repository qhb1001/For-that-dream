



//prim2
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
int n;
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
        q.push(make_pair(-d, u));
    }
    vis[1]=1;
    while(!q.empty()){
        int now=q.top().second;
        int d=q.top().first;
        q.pop();
        if(vis[now]) continue;
//        cout<<(char)(now+'A'-1)<<" get "<<d<<endl;
        vis[now]=1;
        res=res+(-d);
        for(int i=0;i<Edge[now].size();i++){
            int v=Edge[now][i].first;
            int d=Edge[now][i].second;
//            cout<<(char)(v+'A'-1)<<" "<<-d<<endl<<endl;
            q.push(make_pair(-d,v));
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n&&n){
        init();
        for(int i=0;i<n-1;i++){
            char from,to;int k,d;
            cin.get();
            cin>>from>>k;

            for(int i=0;i<k;i++){
                cin.get();
                cin>>to>>d;
                Edge[from-'A'+1].push_back(make_pair(to-'A'+1, d));
                Edge[to-'A'+1].push_back(make_pair(from-'A'+1, d));
            }
        }
        cout<<prim()<<endl;
    }
    return 0;
}
