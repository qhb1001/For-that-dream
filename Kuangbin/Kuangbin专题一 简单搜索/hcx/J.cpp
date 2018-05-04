#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1005;
const int INF=0x3f3f3f3f;
int mmap[maxn][maxn];
int vis[maxn][maxn];
struct ty{
    int x,y;
    int times;
};
vector<ty>Fire;
int ans,r,c;
ty now;
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
void bfs(){
    queue<ty>p;
    p.push(now);
    while(!p.empty()){
        ty tmp=p.front();
        p.pop();
        for(int i=0;i<4;i++){
            int xx=tmp.x+dirx[i];
            int yy=tmp.y+diry[i];
            if(xx<0||yy<0||xx>=r||yy>=c){
                ans=tmp.times+1;
                return ;
            }
            if(vis[xx][yy]||mmap[xx][yy]==-1||(mmap[xx][yy]!=-2&&mmap[xx][yy]<=tmp.times+1)){
                continue;
            }
            vis[xx][yy]=1;
            ty next;next.x=xx;next.y=yy;next.times=tmp.times+1;
            p.push(next);
        }
    }
    ans=-1;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d%d",&r,&c);
        memset(vis, 0, sizeof(vis));
        Fire.clear();
        ans=INF;

        for(int i=0;i<r;i++){
            string s;cin>>s;
            for(int j=0;j<c;j++){
                if(s[j]=='#'){
                    mmap[i][j]=-1;
                }
                else if(s[j]=='J'){
                    now.x=i;now.y=j;now.times=0;
                    vis[i][j]=1;
                }
                else if(s[j]=='F'){
                    ty tmp;tmp.x=i;tmp.y=j;
                    Fire.push_back(tmp);
                    mmap[i][j]=0;
                }
                else{
                    mmap[i][j]=-2;
                }
            }
        }
        int n=Fire.size();
        queue<ty>q;
        for(int i=0;i<n;i++){
            q.push(Fire[i]);
        }
        while(!q.empty()){
            ty tmp=q.front();
            q.pop();
            int x=tmp.x,y=tmp.y;
            for(int i=0;i<4;i++){
                int xx=x+dirx[i];
                int yy=y+diry[i];
                if(xx<0||yy<0||xx>=r||yy>=c){
                    continue;
                }
                if(mmap[xx][yy]==-2){
                    mmap[xx][yy]=mmap[x][y]+1;
                    ty next;next.x=xx;next.y=yy;
                    q.push(next);
                }
            }
        }
        bfs();
        if(ans==-1){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}
