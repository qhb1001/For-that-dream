#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
struct Monster{
    int a,b,pos;
    bool operator<(const Monster& other)const{
        if(a<=b){
            if(other.a<other.b){
                return a>other.a;
            }else{
                return false;
            }
        }else{
            if(other.a<=other.b){
                return true;
            }else{
                return b<other.b;
            }
        }
    }
}m[maxn],tmp;
priority_queue<Monster>q;
vector<int>edge[maxn];
//int f[maxn],cnt[maxn];
bool vis[maxn];
int n,killed;
ll ans,remain;
void init(){
    while(!q.empty()) q.pop();
    for(int i=1;i<=n;i++) edge[i].clear();
    ans=remain=0;killed=1;
    memset(vis,0,sizeof(vis));
}

//int Find(int x){
//    if(x==f[x]) return x;
//    return f[x]=Find(f[x]);
//}
//
//void Union(int x,int y){
//    int a=Find(x),b=Find(y);
//    if(a==b)return ;
//    if(cnt[a]<cnt[b]){
//        f[a]=b;
//        cnt[b]+=cnt[a];
//    }else{
//        f[b]=a;
//        cnt[a]+=cnt[b];
//    }
//}
//
//void dfs(int now,int pre){
//    f[now]=pre;
//    int len=edge[now].size();
//    int nxt;
//    for(int i=0;i<len;i++){
//        nxt=edge[now][i];
//        if(nxt==pre) continue;
//        dfs(nxt, now);
//    }
//}

void solve(){
    while(killed<n){
        tmp=q.top();q.pop();
        if(remain-tmp.a<0){
            ans+=tmp.a-remain;
            remain=tmp.b;
        }else{
            remain=remain-tmp.a+tmp.b;
        }
        killed++;
        vis[tmp.pos]=1;
//        cout<<tmp.pos<<endl;
        int len=edge[tmp.pos].size();
        for(int i=0;i<len;i++){
            if(!vis[edge[tmp.pos][i]]){
                q.push(m[edge[tmp.pos][i]]);
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.a", "w", stdout);
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        for(int i=2;i<=n;i++){
            scanf("%d%d",&m[i].a,&m[i].b);
            m[i].pos=i;
        }
        for(int i=2;i<=n;i++){
            int x,y;scanf("%d%d",&x,&y);
            edge[x].push_back(y);edge[y].push_back(x);
        }
        vis[1]=1;
        int len=edge[1].size();
        for(int i=0;i<len;i++){
            q.push(m[edge[1][i]]);
        }
        solve();
        printf("%lld\n",ans);
    }
}