#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int vis[200005];
int n, m, ans;
struct node{
    int x, step;
};
queue<node> Q;
void bfs(){
    node p,q;
    int i,j;
    p.x=n,p.step=0;
    Q.push(p);
    while(!Q.empty()){
        p=Q.front();
        Q.pop();
        if(p.x==m){
            ans=p.step;
            return ;
        }
        p.step++;
        if(p.x<m&&!vis[p.x]){
            q=p;
            q.x*=2;
            Q.push(q);
        }
        if(p.x>0&&!vis[p.x]){
            q=p;
            q.x--;
            Q.push(q);
        }
        if(!vis[p.x]){
            q=p;
            q.x++;
            Q.push(q);
            vis[p.x]=1;
        }
    }
}
int main(){
    while(cin>>n>>m){
        while(!Q.empty())
            Q.pop();
        memset(vis,0,sizeof(vis));
        ans=0;
        bfs();
        cout<<ans<<endl;
    }
    return 0;
}
