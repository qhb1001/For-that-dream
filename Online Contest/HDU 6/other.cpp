#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
namespace Input
{
    const int BUF = 65536;
    char buf[BUF + 1];
    char *head = buf, *tail = buf;
}
inline char inputchar()
{
    using namespace Input;
    if(head == tail)
        *(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
    return *head++;
}
inline void inputnum(int &ret)
{
    char ch = inputchar();
    while(ch < '0' || ch > '9')
        ch = inputchar();
    ret = ch - '0';
    ch = inputchar();
    while(ch >= '0' && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = inputchar();
    }
}
const int MAXN = 101010;
const int TO_V = 0;
const int TO_W = 1;
const int LOCK_W = 2;
int n, to[MAXN], tp[MAXN];
class Edge
{
public:
    int to, next;
}e[MAXN];
int head[MAXN], en;
void insert(int u, int v)
{
    e[++en].to = v;
    e[en].next = head[u];
    head[u] = en;
}
int vis[MAXN], cnt[MAXN];
queue<int> q;
void dfs1(int p, int label, int c)
{
    vis[p] = label;
    cnt[p] = c;
    if(tp[p] == TO_W)
        c++;
    if(vis[to[p]])
    {
        if(vis[to[p]] == label)
        {
            if(c == cnt[to[p]] + 1)
            {
                if(tp[p] == TO_W)
                {
                    tp[to[p]] = LOCK_W;
                    q.push(to[p]);
                }
                else
                {
                    for(int i = to[p]; i != p; i = to[i])
                        if(tp[i] == TO_W)
                        {
                            tp[to[i]] = LOCK_W;
                            q.push(to[i]);
                            break;
                        }
                }
            }
        }
        return;
    }
    dfs1(to[p], label, c);
}
void solve()
{
    inputnum(n);
    en = 0;
    memset(head, 0, (n + 2) * sizeof(int));
    memset(vis, 0, (n + 2) * sizeof(int));
    for(int i = 1; i <= n; i++)
    {
        inputnum(to[i]);
        insert(to[i], i);
        char ch = inputchar();
        while(ch != 'v' && ch != 'w')
            ch = inputchar();
        if(ch == 'v')
        {
            tp[i] = TO_V;
            while(ch != 'r')
                ch = inputchar();
        }
        else
        {
            tp[i] = TO_W;
            while(ch != 'f')
                ch = inputchar();
        }
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs1(i, i, 0);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = head[now]; i > 0; i = e[i].next)
            if(tp[now] == LOCK_W && tp[e[i].to] == TO_V)
            {
                tp[e[i].to] = LOCK_W;
                q.push(e[i].to);
            }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(tp[i] == LOCK_W)
            ans++;
    printf("0 %d\n", ans);
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output.b", "w", stdout);
    int T;
    inputnum(T);
    for(int t1 = 1; t1 <= T; t1++)
        solve();
    return 0;
}
