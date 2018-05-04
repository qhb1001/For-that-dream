#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int f[maxn],cnt[maxn];
struct ty{
    int u,v;
    ll cost;
}p[maxn];
int n,m,q,x;

bool cmp(ty a,ty b){
    return a.cost<b.cost;
}

void Init(){
    for(int i=0;i<maxn;i++){
        f[i]=i;cnt[i]=1;
    }
}

int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}

void Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(a==b) return ;
    if(cnt[a]<cnt[b]) swap(a,b);
    f[b]=a;
    cnt[a]+=cnt[b];
}

ll kruskal(){
    sort(p+1,p+m,cmp);
//    for(int i=1;i<m;i++){
//        cout<<p[i].u<<" "<<p[i].v<<" "<<p[i].cost<<endl;
//    }
    ll res=0;
    for(int i=1;i<m;i++){
        if(Find(p[i].u)!=Find(p[i].v)){
            Union(p[i].u, p[i].v);
            res+=p[i].cost;
        }
    }
    return res;
}

int main() {
    while(scanf("%d",&n)!=EOF){
        m=1;
        Init();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j){
                    scanf("%d",&x);
                    continue;
                }
                p[m].u=i;p[m].v=j;
                scanf("%lld",&p[m].cost);
                m++;
            }
        }
        scanf("%d",&q);
        while(q--){
            int from,to,d=0;
            scanf("%d%d",&from,&to);
            p[m].u=from;p[m].v=to;p[m].cost=d;
            m++;
        }
        printf("%lld\n",kruskal());
    }
    return 0;
}
