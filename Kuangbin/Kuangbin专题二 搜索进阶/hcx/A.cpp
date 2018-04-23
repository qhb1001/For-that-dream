// 广搜+哈希
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

char t[1000];
int c[10];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char path[10]={'u','d','l','r'};
char op[5],input[20];
int ans;
stack<int>S;
struct Node{
    int s,p;
    Node(){}
    Node(int S,int P){s=S;p=P;}
};

struct Path{
    int from,dir;
}pa[400000];

bool f[400000];

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
                t[i]=j+'0'+1; if(t[i]=='9') t[i]='x';
                flag[j]=1;break;
            }
        }
    }
}

void bfs(int val,int Pos){
    queue<Node>Q;
    Q.push(Node(val,Pos));
    f[val]=1; pa[val].from=-1;pa[val].dir=-1;

    while(!Q.empty()){
        Node h=Q.front(); Q.pop();

        if(h.s==0){
            ans=1;
            int now=h.s;
            while(1){
                if(pa[now].from==-1) break;
                S.push(pa[now].dir);
                now=pa[now].from;
            }
            break;
        }

        int a=h.p/3, b=h.p%3; getstr(h.s);

        for(int i=0;i<4;i++){
            int x=a+dir[i][0],y=b+dir[i][1];
            if(!(x>=0&&x<=2&&y>=0&&y<=2)) continue;
            int newpos=3*x+y;
            swap(t[newpos],t[h.p]);
            int news=getnum();
            if(f[news]) {swap(t[newpos],t[h.p]);continue;}
            pa[news].from=h.s; pa[news].dir=i;f[news]=1;
            Q.push(Node(news,newpos));
            swap(t[newpos],t[h.p]);
        }
    }
}

int main(){
    c[0]=1; for(int i=1;i<=8;i++) c[i]=c[i-1]*i;
    while(~scanf("%s",op)){
        t[0]=op[0];
        int pos;
        for(int i=1;i<=8;i++){
            scanf("%s",op); t[i]=op[0];
            if(t[i]=='x') pos=i;
        }
        int state=getnum();

        int sum=0;
        for(int i=0;t[i];i++){
            if(t[i]=='x') continue;
            for(int j=0;j<i;j++){
                if(t[j]=='x') continue;
                if(t[i]<t[j]) sum++;
            }
        }

        if(sum%2==1) { printf("unsolvable\n"); continue; }

        ans=0;
        memset(f,0,sizeof f);
        bfs(state,pos);

        while(!S.empty()){
            printf("%c",path[S.top()]);
            S.pop();
        }
        printf("\n");
    }
    return 0;
}

//my
// #include <iostream>
// #include <string>
// #include <cstdio>
// #include <algorithm>
// #include <cstring>
// #include <queue>
// using namespace std;
// const int maxn=4e5+10;
// int n;
// string anss;
// bool vis[maxn];
// const string R="123456789";
// int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
// struct ty{
//     string now;
//     string path;
//     int depth;
//     int idx;
// }xx;
// int cantor(string s){
//     int temp,num;
//     num=0;
//     for(int i=0;i<n-1;i++){//n为位数
//         temp=0;
//         for(int j=i+1;j<n;j++){
//             if(s[j]<s[i]) temp++;
//         }
//         num+=fac[n-i-1]*temp;
//     }
//     return (num+1);
// }

// void bfs(){
//     queue<ty>q;
//     q.push(xx);
//     while(!q.empty()){
//         ty xxx=q.front();
//         q.pop();
//         ty next;
//         next.now=xxx.now;next.path=xxx.path;next.depth=xxx.depth+1;
//         if(xxx.idx>2){
//             next.path+='u';
//             next.idx=xxx.idx-3;
//             char tmp=next.now[next.idx];
//             next.now[next.idx]='0';
//             next.now[xxx.idx]=tmp;
//             int x=cantor(next.now);
//             //            cout<<next.now<<" "<<next.path<<endl;
//             if(!vis[x]){
//                 vis[x]=1;
//                 if(next.now==R){
//                     anss=next.path;
//                     return ;
//                 }
//                 q.push(next);
//             }
//         }

//         next.now=xxx.now;next.path=xxx.path;next.depth=xxx.depth+1;
//         if(xxx.idx%3){
//             next.path+='l';
//             next.idx=xxx.idx-1;
//             char tmp=next.now[next.idx];
//             next.now[next.idx]='0';
//             next.now[xxx.idx]=tmp;
//             int x=cantor(next.now);
// //            cout<<next.now<<" "<<next.path<<endl;
//             if(!vis[x]){
//                 vis[x]=1;
//                 if(next.now==R){
//                     anss=next.path;
//                     return ;
//                 }
//                 q.push(next);
//             }
//         }

//         next.now=xxx.now;next.path=xxx.path;next.depth=xxx.depth+1;
//         if(xxx.idx<6){
//             next.path+='d';
//             next.idx=xxx.idx+3;
//             char tmp=next.now[next.idx];
//             next.now[next.idx]='0';
//             next.now[xxx.idx]=tmp;
//             int x=cantor(next.now);
// //            cout<<next.now<<" "<<next.path<<endl;
//             if(!vis[x]){
//                 vis[x]=1;
//                 if(next.now==R){
//                     anss=next.path;
//                     return ;
//                 }
//                 q.push(next);
//             }
//         }

//         next.now=xxx.now;next.path=xxx.path;next.depth=xxx.depth+1;
//         if((xxx.idx%3)!=2){
//             next.path+='r';
//             next.idx=xxx.idx+1;
//             char tmp=next.now[next.idx];
//             next.now[next.idx]='0';
//             next.now[xxx.idx]=tmp;
//             int x=cantor(next.now);
//             //            cout<<next.now<<" "<<next.path<<endl;
//             if(!vis[x]){
//                 vis[x]=1;
//                 if(next.now==R){
//                     anss=next.path;
//                     return ;
//                 }
//                 q.push(next);
//             }
//         }
//     }
// }

// int main() {
//     string s,tmp;
//     n=9;
//     getline(cin,tmp);
//         anss="";
//         memset(vis,0,sizeof(vis));
//         s="";
//         int num=0,nums=0,sum=0;
//         for(int i=0;i<tmp.length();i++){
//             if(tmp[i]!=' '){
//                 if(tmp[i]=='x'){
//                     nums=num;
//                     s+='0';
//                 }
//                 else s+=tmp[i];
//                 num++;
//             }
//         }
//     for(int i=0;i<9;i++){
//         if(s[i]=='0')continue;
//         for(int j=0;j<i;j++){
//             if(s[j]=='0')continue;
//             if(s[i]<s[j]) sum++;
//         }
//     }
//     if(sum%2){
//         cout<<"unsolvable"<<endl;
//         return 0;
//     }
//     vis[cantor(s)]=1;
//     xx.now=s;xx.depth=0;xx.idx=nums;xx.path="";
//     bfs();
//     if(anss=="")
//         cout<<"unsolvable"<<endl;
//     else cout<<anss<<endl;

//     return 0;
// }

// 广搜+哈希+打表
// #include<cstdio>
// #include<cstring>
// #include<cmath>
// #include<vector>
// #include<map>
// #include<queue>
// #include<stack>
// #include<algorithm>
// using namespace std;

// char t[1000];
// int c[10];
// int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
// char path[10]={'d','u','r','l'};
// char op[5],input[20];

// struct Node
// {
//     int s,p;
//     Node(){}
//     Node(int S,int P){s=S,p=P;}
// };

// struct Path
// {
//     int from,dir;
// }pa[400000];
// bool f[400000];

// int getnum()
// {
//     int res=0;
//     for(int i=0;t[i];i++)
//         for(int j=i+1;t[j];j++)
//             if(t[j]<t[i]) res=res+c[8-i];
//     return res;
// }

// void getstr(int val)
// {
//     int tmp[10],flag[10];
//     memset(flag,0,sizeof flag);
//     for(int i=0;i<9;i++) tmp[i]=val/c[8-i],val=val%c[8-i];
//     for(int i=0;i<9;i++)
//     {
//         int num=0;
//         for(int j=0;j<9;j++)
//         {
//             if(flag[j]==0) num++;
//             if(num==tmp[i]+1)
//             {
//                 t[i]=j+'0'+1; if(t[i]=='9') t[i]='x';
//                 flag[j]=1;break;
//             }
//         }
//     }
// }

// void pre()
// {
//     queue<Node>Q;
//     Q.push(Node(0,8));
//     f[0]=1; pa[0].from=-1,pa[0].dir=-1;

//     while(!Q.empty())
//     {
//         Node h=Q.front(); Q.pop();
//         int a=h.p/3, b=h.p%3; getstr(h.s);
//         for(int i=0;i<4;i++)
//         {
//             int x=a+dir[i][0],y=b+dir[i][1];
//             if(!(x>=0&&x<=2&&y>=0&&y<=2)) continue;
//             int newpos=3*x+y;
//             swap(t[newpos],t[h.p]);
//             int news=getnum();
//             if(f[news]) {swap(t[newpos],t[h.p]);continue;}
//             pa[news].from=h.s, pa[news].dir=i, f[news]=1;
//             Q.push(Node(news,newpos));
//             swap(t[newpos],t[h.p]);
//         }
//     }
// }

// int main()
// {
//     c[0]=1; for(int i=1;i<=8;i++) c[i]=c[i-1]*i;
//     pre();

//     while(~scanf("%s",op))
//     {
//         t[0]=op[0];
//         for(int i=1;i<=8;i++) {scanf("%s",op); t[i]=op[0];}
//         int state=getnum();
//         if(f[state]==0) printf("unsolvable\n");
//         else
//         {
//             while(1)
//             {
//                 if(pa[state].from==-1) break;
//                 printf("%c",path[pa[state].dir]);
//                 state=pa[state].from;
//             }
//             printf("\n");
//         }
//     }
//     return 0;
// }

//#include<cstdio>
// #include<cstring>
// #include<cmath>
// #include<vector>
// #include<map>
// #include<queue>
// #include<stack>
// #include<string>
// #include<algorithm>
// using namespace std;

// char input[1000],t[1000],op[5];
// int c[10];
// struct Node
// {
//     int s,p;
//     Node(){}
//     Node(int S,int P){s=S,p=P;}
// };
// struct Path
// {
//     int from,dir;
// }path[400000];
// int f[400000];

// int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
// string d[3] = {"","udlr","durl"};

// queue<Node>q[3];
// int ans;

// stack<int>S;
// queue<int>Q;

// int getnum()
// {
//     int res=0;
//     for(int i=0;t[i];i++)
//         for(int j=i+1;t[j];j++)
//             if(t[j]<t[i]) res=res+c[8-i];
//     return res;
// }

// void getstr(int val)
// {
//     int tmp[10],flag[10];
//     memset(flag,0,sizeof flag);
//     for(int i=0;i<9;i++) tmp[i]=val/c[8-i],val=val%c[8-i];
//     for(int i=0;i<9;i++)
//     {
//         int num=0;
//         for(int j=0;j<9;j++)
//         {
//             if(flag[j]==0) num++;
//             if(num==tmp[i]+1)
//             {
//                 t[i]=j+'0'+1; if(t[i]=='9') t[i]='x';
//                 flag[j]=1;break;
//             }
//         }
//     }
// }

// bool g(int a, int b)
// {
//     if (a >= 0 && a <= 2 && b >= 0 && b <= 2) return 1;
//     return 0;
// }

// void bfs(int now)
// {
//     Node h=q[now].front(); q[now].pop();
//     int a=h.p/3,b=h.p%3;
//     getstr(h.s);

//     for(int i=0;i<4;i++)
//     {
//         int x=a+dir[i][0],y=b+dir[i][1];
//         if(!g(x,y)) continue;
//         int pos = 3 * x + y;

//         swap(t[h.p],t[pos]);

//         if(f[getnum()]==now) { swap(t[h.p],t[pos]); continue; }
//         else if(f[getnum()]!=0)
//         {
//             ans=1;
//             if(now==1)
//             {
//                 S.push(i);
//                 int u=h.s;
//                 while(path[u].from!=-1) { S.push(path[u].dir); u=path[u].from; }
//                 u=getnum();
//                 while(path[u].from!=-1) { Q.push(path[u].dir); u=path[u].from; }
//             }
//             else
//             {
//                 Q.push(i);
//                 int u=h.s;
//                 while(path[u].from!=-1) { Q.push(path[u].dir); u=path[u].from; }
//                 u=getnum();
//                 while(path[u].from!=-1) { S.push(path[u].dir); u=path[u].from; }
//             }
//             break;
//         }
//         else
//         {
//             f[getnum()]=now;
//             path[getnum()].from=h.s;
//             path[getnum()].dir=i;
//             q[now].push(Node(getnum(),pos));
//             swap(t[h.p],t[pos]);
//         }
//     }
// }

// void read()
// {
//     t[0]=op[0];
//     for(int i=1;i<=8;i++)
//     {scanf("%s",op); t[i]=op[0];}
//     for(int i=0;i<=9;i++) input[i]=t[i];
// }

// void init()
// {
//     memset(f,ans=0,sizeof f);
//     while(!q[1].empty()) q[1].pop();
//     while(!q[2].empty()) q[2].pop();
// }

// void work(int s,int pos)
// {
//     q[1].push(Node(s,pos)); q[2].push(Node(0,8));
//     f[s]=1; path[s].from=path[s].dir=-1;
//     f[0]=2; path[0].from=path[0].dir=-1;
//     while((!q[1].empty())&&(!q[2].empty()))
//     {
//         if(ans==1) break;
//         bfs(1); if(ans==1) break;
//         bfs(2); if(ans==1) break;
//     }
// }

// int main()
// {
//     c[0]=1; for(int i=1;i<=8;i++) c[i]=c[i-1]*i;
//     while(~scanf("%s",op))
//     {
//         read();

//         int sum=0;
//         for(int i=0;t[i];i++)
//         {
//             if(t[i]=='x') continue;
//             for(int j=0;j<i;j++)
//             {
//                 if(t[j]=='x') continue;
//                 if(t[i]<t[j]) sum++;
//             }
//         }

//         if(sum%2==1)
//         {
//             printf("unsolvable\n");
//             continue;
//         }
//         init();
//         for(int i=0;i<9;i++)
//             if(input[i]=='x'){work(getnum(),i); break; }
//         if(ans==1)
//         {
//             while(!S.empty()) { printf("%c",d[1][S.top()]); S.pop(); }
//             while(!Q.empty()) { printf("%c",d[2][Q.front()]); Q.pop(); }
//         }
//         else printf("unsolvable");
//         printf("\n");
//     }
//     return 0;
// }

