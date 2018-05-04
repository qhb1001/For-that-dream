//POJ 3278
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e5+10;
bool vis[maxn];
int k;
int ans=0;
struct ty{
    int now;
    int times;
}n;
void bfs(){
    queue<ty>q;
    q.push(n);
    while(!q.empty()){
        ty tmp=q.front();
        q.pop();
        if(tmp.now==k){
            ans=tmp.times;
            break;
        }
        ty next;next.times=tmp.times+1;
        int x=tmp.now*2,y=tmp.now+1,z=tmp.now-1;
        if(x<maxn&&!vis[x]){
            next.now=x;
            q.push(next);
            vis[x]=1;
        }
        if(!vis[y]&&y<maxn){
            next.now=y;
            q.push(next);
            vis[y]=1;
        }
        if(!vis[z]&&z>=0){
            next.now=z;
            q.push(next);
            vis[z]=1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n.now>>k;
    if(n.now>=k){
        cout<<n.now-k<<endl;
        return 0;
    }

    n.times=0;
    memset(vis,0,sizeof(vis));
    vis[n.now]=1;

    bfs();
    cout<<ans<<endl;
    return 0;
}
