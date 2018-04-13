#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn=105;
bool mmap[maxn][maxn];
int dirx[]={0,0,1,-1,1,-1,1,-1};
int diry[]={1,-1,0,0,-1,-1,1,1};
int n,m;
void dfs(int x,int y){
    for(int i=0;i<8;i++){
        int xx=x+dirx[i];
        int yy=y+diry[i];
        if(xx<0||yy<0||xx>=n||yy>=m) continue;
        if(mmap[xx][yy]){
            mmap[xx][yy]=0;
            dfs(xx, yy);
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(!n&&!m){
            break;
        }

        for(int i=0;i<n;i++){
            string s;cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='@'){
                    mmap[i][j]=1;
                }
                else mmap[i][j]=0;
            }
        }

        int num=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mmap[i][j]){
                    num++;
                    dfs(i, j);
                }
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
