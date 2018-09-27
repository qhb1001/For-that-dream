#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
namespace IO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    #define ll long long 
    //fread->read 

    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
            //{printf("IO error!\n");system("pause");for (;;);exit(0);} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(ll &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    inline void read(double &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (ch=='.'){ 
            double tmp=1; ch=nc(); 
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0'); 
        } 
        if (sign)x=-x; 
    } 
    inline void read(char *s){ 
        char ch=nc(); 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch; 
        *s=0; 
    } 
    inline void read(char &c){ 
        for (c=nc();blank(c);c=nc()); 
        if (IOerror){c=-1;return;} 
    } 
    //fwrite->write 
    struct Ostream_fwrite{ 
        char *buf,*p1,*pend; 
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
        void out(char ch){ 
            if (p1==pend){ 
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
            } 
            *p1++=ch; 
        } 
        void print(int x){ 
            static char s[15],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); 
        } 
        void println(int x){ 
            static char s[15],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void print(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); 
        } 
        void println(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void print(double x,int y){ 
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000, 
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL, 
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL}; 
            if (x<-1e-12)out('-'),x=-x;x*=mul[y]; 
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1; 
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2); 
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);} 
        } 
        void println(double x,int y){print(x,y);out('\n');} 
        void print(char *s){while (*s)out(*s++);} 
        void println(char *s){while (*s)out(*s++);out('\n');} 
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
        ~Ostream_fwrite(){flush();} 
    }Ostream; 
    inline void print(int x){Ostream.print(x);} 
    inline void println(int x){Ostream.println(x);} 
    inline void print(char x){Ostream.out(x);} 
    inline void println(char x){Ostream.out(x);Ostream.out('\n');} 
    inline void print(ll x){Ostream.print(x);} 
    inline void println(ll x){Ostream.println(x);} 
    inline void print(double x,int y){Ostream.print(x,y);} 
    inline void println(double x,int y){Ostream.println(x,y);} 
    inline void print(char *s){Ostream.print(s);} 
    inline void println(char *s){Ostream.println(s);} 
    inline void println(){Ostream.out('\n');} 
    inline void flush(){Ostream.flush();}
    #undef ll 
    #undef OUT_SIZE 
    #undef BUF_SIZE 
};
using namespace IO;
using namespace std;
const int MAX = 1e5 + 5;
int n, m, head[MAX], cnt, pre[MAX];
long long d[MAX];
struct Edge {
    int to, nex;
    long long cost;
}e[MAX<<1];
void add(int u, int v, int cost) {
    e[++cnt] = (Edge){v, head[u], cost};
    head[u] = cnt;
}
bool vis[MAX];
void dijkstra() {    
    for (int i = 1; i <= n; ++i) d[i] = 1LL<<50;
    d[1] = 0;
    pair<long long, int> now;
    int u, v;
    long long Min;
    while (true) {
        Min = 1LL<<50;
        for (int i = 1; i <= n; ++i) if (!vis[i] && Min > d[i]) {Min = d[i]; u = i;}
        vis[u] = 1;
        if (u == n) return ;
        if (Min == 1LL<<50) break;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (d[v] > d[u] + e[i].cost) {
                d[v] = d[u] + e[i].cost;
                pre[v] = u;
            }
        }
    }
}
int ans[MAX], top;
int fa[MAX], cnt_[MAX];
int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void unit(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return ;
    if (cnt_[v] > cnt_[u])    swap(u, v);
    cnt_[u] += cnt_[v];
    fa[v] = u;
}


void spfa() {
    for (int i = 1; i <= n; ++i) d[i] = 1LL<<50;
    d[1] = 0;
    queue<int>q;
    q.push(1);
    vis[1] = true;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop(); vis[u] = false;
        for (int i = head[u]; i; i = e[i].nex) {
            v = e[i].to;
            if (d[v] > d[u] + e[i].cost) {
                d[v] = d[u] + e[i].cost;
                pre[v] = u;
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main() { 
    read(n); read(m); 
    for (int i = 1; i <= n; ++i)    fa[i] = i, cnt_[i] = 1;

    int u, v, c;
    while (m--) {
        read(u); read(v); read(c); 
        unit(u, v);
        add(u, v, c);
        add(v, u, c);
    }
    if (find(1) != find(n)) {
        println(-1);
        return 0;
    }
    
    spfa(); 
    
    if (pre[n] == 0)   println(-1);
    else {
        int now = n;
        while (true) {
            ans[++top] = now; now = pre[now];
            if (now == 1)   {ans[++top] = now; break;}
        }

        for (int i = top; i >= 1; --i)  print(ans[i]), print(' ');
    }
}