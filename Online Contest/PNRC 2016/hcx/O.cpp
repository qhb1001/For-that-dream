#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
const int maxn=55;
const int INF=0x3f3f3f;
struct ty{
    int x,y,idx;
};
queue<ty>q;

int n,m,sx,sy;
string mmap[maxn];
string cmd;
int dp[maxn][maxn][maxn];//(i,j) in k orders,min add
bool vis[maxn][maxn][maxn];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int spfa(){
    int res=INF;
    memset(dp,INF,sizeof(dp));
    dp[sx][sy][0]=0;
    q.push({sx,sy,0});

    while(!q.empty()){
        ty tmp=q.front();q.pop();
        vis[tmp.x][tmp.y][tmp.idx]=0;

        if(mmap[tmp.x][tmp.y]=='E'){
            res=min(res,dp[tmp.x][tmp.y][tmp.idx]);
            continue;
        }

        for(int i=0;i<4;i++){
            int nx=tmp.x+dx[i],ny=tmp.x+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||mmap[nx][ny]=='#'){//need skip

                if(){

                }
                continue;
            }
        }
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>mmap[i];
        for(int j=0;j<m;j++){
            if(mmap[i][j]=='R'){
                sx=i;sy=j;
            }
        }
    }
    cin>>cmd;

    return 0;
}
