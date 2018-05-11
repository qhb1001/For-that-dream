#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int maxx=800;
int f[maxx],cnt[maxx];
struct cells{
    int x,y;
}Node[maxx];
struct ty{
    int u,v;
    double cost;
}p[maxn];
int n,m,k;

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
    for(int i=1;i<m;i++){
        if(Union(p[i].u, p[i].v)){
            printf("%d %d\n",p[i].u,p[i].v);
        }
    }
    return ;
}

double dist(int i,int j){
    double x=Node[i].x-Node[j].x;
    double y=Node[i].y-Node[j].y;
    return sqrt(x*x+y*y);
}

int main() {
    scanf("%d",&n);
    Init();
    for(int i=1;i<=n;i++){
        scanf("%d%d",&Node[i].x,&Node[i].y);
    }
    
    scanf("%d",&k);
    int a,b;
    while(k--){
        scanf("%d%d",&a,&b);
        Union(a, b);
    }
    
    m=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            p[m].u=i;p[m].v=j;
            p[m].cost=dist(i, j);
            m++;
        }
    }
    kruskal();
    return 0;
}
