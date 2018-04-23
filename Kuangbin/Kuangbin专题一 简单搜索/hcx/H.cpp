#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=105;
bool vis[maxn][maxn];
int a,b,c;
struct ty{
    int f,n;
    string s;
    int times;
};
void bfs(){
    queue<ty>q;
    ty now;now.f=0;now.n=0;now.s="";now.times=0;
    vis[0][0]=1;
    q.push(now);
    while(!q.empty()){
        ty tmp=q.front();
        q.pop();

        ty next;next.f=tmp.f;next.n=tmp.n;next.s=tmp.s;next.times=tmp.times+1;
        if(!vis[a][next.n]){
            next.f=a;
            next.s+="FILL(1)\n";
            vis[next.f][next.n]=1;
            if(next.f==c||next.n==c){
                cout<<next.times<<endl<<next.s;
                return ;
            }
            q.push(next);
        }

        next.f=tmp.f;next.n=tmp.n;next.s=tmp.s;next.times=tmp.times+1;
        if(!vis[next.f][b]){
            next.n=b;
            next.s+="FILL(2)\n";
            vis[next.f][b]=1;
            if(next.f==c||next.n==c){
                cout<<next.times<<endl<<next.s;
                return ;
            }
            q.push(next);
        }

        next.f=tmp.f;next.n=tmp.n;next.s=tmp.s;next.times=tmp.times+1;
        if(!vis[0][next.n]){
            next.f=0;
            next.s+="DROP(1)\n";
            vis[next.f][next.n]=1;
            q.push(next);
        }

        next.f=tmp.f;next.n=tmp.n;next.s=tmp.s;next.times=tmp.times+1;
        if(!vis[next.f][0]&&next.n){
            next.n=0;
            next.s+="DROP(2)\n";
            vis[next.f][next.n]=1;
            q.push(next);
        }

        next.f=tmp.f;next.n=tmp.n;next.s=tmp.s;next.times=tmp.times+1;
        int add=min(a-next.f,next.n);
        if(!vis[next.f+add][next.n-add]){
            next.f+=add;
            next.n-=add;
            next.s+="POUR(2,1)\n";
            if(next.f==c||next.n==c){
                cout<<next.times<<endl<<next.s;
                return ;
            }
            vis[next.f][next.n]=1;
            q.push(next);
        }

        next.f=tmp.f;next.n=tmp.n;next.s=tmp.s;next.times=tmp.times+1;
        add=min(b-next.n,next.f);
        if(!vis[next.f-add][next.n+add]){
            next.n+=add;
            next.f-=add;
            next.s+="POUR(1,2)\n";
            if(next.f==c||next.n==c){
                cout<<next.times<<endl<<next.s;
                return;
            }
            vis[next.f][next.n]=1;
            q.push(next);
        }
    }
    cout<<"impossible"<<endl;
    return ;
}

int main(){
    scanf("%d%d%d",&a,&b,&c);
    bfs();
    return 0;
}
