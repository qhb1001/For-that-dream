//Kruskal
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
int n,m;

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
    return 0;
}

