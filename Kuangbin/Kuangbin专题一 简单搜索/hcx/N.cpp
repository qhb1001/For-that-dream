#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=202;
bool mmap[maxn][maxn];
bool vis[maxn][maxn];
int disty[maxn][maxn],distm[maxn][maxn];
int n,m;
int num;
struct ty{
    int x,y;
}yy,mm;
vector<ty>KFC;
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
void bfs(ty now,int dist[][maxn]){
    queue<ty>q;
    q.push(now);
    vis[now.x][now.y]=1;
    dist[now.x][now.y]=0;
    while(!q.empty()){
        ty tmp=q.front();
        q.pop();
//        cout<<tmp.x<<" "<<tmp.y<<" "<<dist[tmp.x][tmp.y]<<endl;
        for(int i=0;i<4;i++){
            int dx=tmp.x+dirx[i];
            int dy=tmp.y+diry[i];
            if(dx<0||dy<0||dx>=n||dy>=m)
                continue;
            if(!mmap[dx][dy]||vis[dx][dy]) continue;
            vis[dx][dy]=1;
            dist[dx][dy]=dist[tmp.x][tmp.y]+1;
//            cout<<dx<<" "<<dy<<endl;
            ty next;next.x=dx;next.y=dy;
            q.push(next);
        }
//        cout<<endl;
    }
}

int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(mmap, 0, sizeof(mmap));
        memset(disty, -1, sizeof(disty));
        memset(distm, -1, sizeof(distm));
        num=0;
        KFC.clear();
        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='Y'){
                    yy.x=i;yy.y=j;
                }
                else if(s[j]=='M'){
                    mm.x=i;mm.y=j;
                }
                else if(s[j]=='.'){
                    mmap[i][j]=1;
                }
                else if(s[j]=='@'){
                    ty tmp;tmp.x=i;tmp.y=j;
                    KFC.push_back(tmp);
                    mmap[i][j]=1;
                }
            }
        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<mmap[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        memset(vis, 0, sizeof(vis));
        bfs(yy,disty);
        memset(vis, 0, sizeof(vis));
        bfs(mm,distm);
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<disty[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                cout<<distm[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//
        int len=KFC.size();
        int ans=0x3f3f3f;
        for(int i=0;i<len;i++){
            int kx=KFC[i].x,ky=KFC[i].y;
            int a=disty[kx][ky],b=distm[kx][ky];
            if(a==-1||b==-1) continue;
            else ans=min(ans,a+b);
        }
        cout<<ans*11<<endl;
    }
    return 0;
}
