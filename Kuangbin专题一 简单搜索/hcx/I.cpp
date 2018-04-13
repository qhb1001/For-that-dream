#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int maxn=12;
const int INF=1e9;
bool mmap[maxn][maxn];
bool vis[maxn][maxn];
int dirx[]={0,0,-1,1};
int diry[]={1,-1,0,0};
int x[105],y[105];
int n,m;
int ans,num;
int aa,bb,a,b;
struct ty{
    int x,y,times;
};
void bfs(){
    ty one,two;
    one.x=a;one.y=b;one.times=0;
    two.x=aa;two.y=bb;two.times=0;
    queue<ty>q;
    while(!q.empty()) q.pop();
    q.push(one);
    q.push(two);
    int res=num-2;
    vis[a][b]=vis[aa][bb]=1;

    while(!q.empty()){
        ty tmp=q.front();
        q.pop();
        int x1=tmp.x;
        int y1=tmp.y;
        for(int i=0;i<4;i++){
            int xx=x1+dirx[i];
            int yy=y1+diry[i];
            if(xx<0||yy<0||xx>=n||yy>=m){
                continue;
            }
            if(mmap[xx][yy]&&!vis[xx][yy]){
                vis[xx][yy]=1;
                res--;
                ty next;next.x=xx;next.y=yy;next.times=tmp.times+1;
//                cout<<xx<<" "<<yy<<" "<<res<<" "<<next.times<<endl;
                if(!res){
                    ans=min(ans,next.times);
//                    cout<<ans<<endl;
                    return ;
                }
                q.push(next);
            }
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        memset(mmap, 0, sizeof(mmap));
        scanf("%d%d",&n,&m);
        num=0;ans=INF;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if(s[j]=='#'){
                    mmap[i][j]=1;
                    x[num]=i;y[num]=j;
                    num++;
                }
            }
        }
//        cout<<"num: "<<num<<endl;
        if(num<=2){
            cout<<"Case "<<i<<": "<<"0"<<endl;
            continue;
        }

        for(int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                a=x[i];b=y[i];
                aa=x[j];bb=y[j];
                memset(vis, 0, sizeof(vis));
//                cout<<a<<" "<<b<<" "<<aa<<" "<<bb<<endl;
                bfs();
//                cout<<endl;
            }
        }

        if(ans==INF){
            cout<<"Case "<<i<<": "<<"-1"<<endl;
        }
        else{
            cout<<"Case "<<i<<": "<<ans<<endl;
        }
    }
    return 0;
}
