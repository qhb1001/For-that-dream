#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int dirx[]={0,0,-1,1};
int diry[]={1,-1,0,0};
int mmap[6][6];
string ans;
int dep=0x3f3f3f3f;;
void dfs(int x,int y,string paths,int depth){
    for(int i=0;i<4;i++){
        int xx=x+dirx[i];
        int yy=y+diry[i];
        if(xx<0||yy<0||x>=5||y>=5){
            continue;
        }
        if(mmap[xx][yy]){
            continue;
        }
        mmap[xx][yy]=1;
        string next=paths;
        next+="(";
        next+=xx+'0';
        next+=", ";
        next+=yy+'0';
        next+=")\n";
        if(xx==4&&yy==4){
            if(depth<dep){
                dep=depth;
                ans=next;
            }
            return ;
        }
        dfs(xx, yy, next, depth+1);
    }
}
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>mmap[i][j];
        }
    }
    ans="";
    dfs(0, 0, "(0, 0)\n", 0);
    cout<<ans;
}
