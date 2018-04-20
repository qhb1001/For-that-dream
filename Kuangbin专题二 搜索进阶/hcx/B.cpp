#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

char input[1000],inputs[1000],t[1000];
int c[10];
struct Node{
    int s,p;
    Node(){}
    Node(int S,int P){s=S;p=P;}
};
struct Path{
    int from,dir;
}path[400000];
int f[400000];

int dir[4][2] = {{ 1,0 }, { 0,-1 },{ 0,1 },{ -1,0 }};
string d[3] = {"","dlru","urld"};

queue<Node>q[3];
int ans;

stack<int>S;
queue<int>Q;

int getnum(){
    int res=0;
    for(int i=0;t[i];i++)
        for(int j=i+1;t[j];j++)
            if(t[j]<t[i]) res=res+c[8-i];
    return res;
}

void getstr(int val){
    int tmp[10],flag[10];
    memset(flag,0,sizeof flag);
    for(int i=0;i<9;i++) {tmp[i]=val/c[8-i];val=val%c[8-i];}
    for(int i=0;i<9;i++){
        int num=0;
        for(int j=0;j<9;j++){
            if(flag[j]==0) num++;
            if(num==tmp[i]+1){
                t[i]=j+'0'+1; if(t[i]=='9') t[i]='X';
                flag[j]=1;break;
            }
        }
    }
}

bool g(int a, int b){
    if (a >= 0 && a <= 2 && b >= 0 && b <= 2) return 1;
    return 0;
}

void bfs(int now){
    Node h=q[now].front(); q[now].pop();
    int a=h.p/3,b=h.p%3;
    getstr(h.s);

    for(int i=0;i<4;i++){
        int x=a+dir[i][0],y=b+dir[i][1];
        if(!g(x,y)) continue;
        int pos = 3 * x + y;

        swap(t[h.p],t[pos]);

        if(f[getnum()]==now) { swap(t[h.p],t[pos]); continue; }
        else if(f[getnum()]!=0){
            ans=1;
            if(now==1){
                S.push(i);
                int u=h.s;
                while(path[u].from!=-1) { S.push(path[u].dir); u=path[u].from; }
                u=getnum();
                while(path[u].from!=-1) { Q.push(path[u].dir); u=path[u].from; }
            }
            else{
                Q.push(i);
                int u=h.s;
                while(path[u].from!=-1) { Q.push(path[u].dir); u=path[u].from; }
                u=getnum();
                while(path[u].from!=-1) { S.push(path[u].dir); u=path[u].from; }
            }
            break;
        }
        else{
            f[getnum()]=now;
            path[getnum()].from=h.s;
            path[getnum()].dir=i;
            q[now].push(Node(getnum(),pos));
            swap(t[h.p],t[pos]);
        }
    }
}

void read(){
    scanf("%s",t);
    for(int i=0;i<=9;i++) input[i]=t[i];
}

void reads(){
    scanf("%s",t);
    for(int i=0;i<=9;i++) inputs[i]=t[i];
}

void init(){
    memset(f,ans=0,sizeof f);
    while(!q[1].empty()) q[1].pop();
    while(!q[2].empty()) q[2].pop();
}

void work(int s,int pos,int ss,int poss){
    q[1].push(Node(s,pos)); q[2].push(Node(ss,poss));
    f[s]=1; path[s].from=path[s].dir=-1;
    f[0]=2; path[0].from=path[0].dir=-1;
    while((!q[1].empty())&&(!q[2].empty())){
        if(ans==1) break;
        bfs(1); if(ans==1) break;
        bfs(2); if(ans==1) break;
    }
}

int main(){
    c[0]=1; for(int i=1;i<=8;i++) c[i]=c[i-1]*i;
    int T;scanf("%d",&T);
    for(int i=1;i<=T;i++){
        read();
        int num=getnum();
        reads();
        int nums=getnum();
        init();
        int idx=0,idxx=0;
        for(int i=0;i<9;i++)
            if(input[i]=='X'){
                idx=i;
                break;
            }
        for(int i=0;i<9;i++)
            if(inputs[i]=='X'){
                idxx=i;
                break;
            }

        work(num,idx,nums,idxx);
        printf("Case %d: %d\n",i,S.size()+Q.size());
        while(!S.empty()) { printf("%c",d[1][S.top()]); S.pop(); }
        while(!Q.empty()) { printf("%c",d[2][Q.front()]); Q.pop(); }
        printf("\n");
    }
    return 0;
}

