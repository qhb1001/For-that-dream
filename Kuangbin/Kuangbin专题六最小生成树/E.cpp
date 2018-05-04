#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int maxx=1010;
int f[maxx],cnt[maxx];
int node[maxn];
struct ty{
    int u,v;
    ll cost;
}p[maxn];
int n,m,x;

bool cmp(ty a,ty b){
    return a.cost<b.cost;
}

void Init(){
    for(int i=1;i<=n;i++){
        f[i]=i;cnt[i]=1;
    }
}

int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}

bool Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(a==b) return false;
    if(cnt[a]<cnt[b]) swap(a,b);
    f[b]=a;
    cnt[a]+=cnt[b];
    return true;
}

void kruskal(){
    sort(p+1,p+m,cmp);
    ll res=0;
    for(int i=1;i<m;i++){
       if(Union(p[i].u, p[i].v)){
            res+=p[i].cost;
        }
    }
    printf("%lld\n",res);
}

int main() {
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&node[i]);
        Init();
        m=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j){
                    scanf("%d",&x);
                    continue;
                }
                p[m].u=i;p[m].v=j;
                scanf("%lld",&p[m].cost);
                p[m].cost+=node[i]+node[j];
                m++;
            }
        }
        kruskal();
    }
    return 0;
}
