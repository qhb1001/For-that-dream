#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int dirx[]={0,0,1,-1};
int diry[]={1,-1,0,0};
int cnt=0,num=0;
bool vis[55][55];
string s[55];
int n,m;
void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int xx=x+dirx[i];
        int yy=y+diry[i];
        if(xx<0||xx>=n||yy<0||yy>=m) continue;
        if(!vis[xx][yy]&&s[xx][yy]!='W'){
            vis[xx][yy]=1;
            dfs(xx,yy);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='L'&&!vis[i][j]){
                ans++;
                vis[i][j]=1;
                dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
