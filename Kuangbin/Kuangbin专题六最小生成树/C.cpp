#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxx=110;
int f[maxx];
struct cells{
    double x,y,z,r;
}node[maxx];
struct ty{
    int u,v;
    double cost;
}p[maxx*maxx];
int n,m;

bool cmp(ty a,ty b){
    return a.cost<b.cost;
}

void Init(){
    for(int i=0;i<=n;i++){
        f[i]=i;
    }
}

int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}

double kruskal(){
    Init();
    sort(p,p+m,cmp);
    double res=0;
    int ans=0;
    for(int i=0;i<m;i++){
        int a=Find(p[i].u),b=Find(p[i].v);
        if(a!=b){
            f[b]=a;
            res+=p[i].cost;
            ans++;
        }
    }
    return res;
}

double dist(cells &a,cells &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

int main() {
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++) scanf("%lf%lf%lf%lf",&node[i].x,&node[i].y,&node[i].z,&node[i].r);
        m=0;
        double t;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                p[m].u=i;p[m].v=j;
                t=dist(node[i],node[j])-node[i].r-node[j].r;
                if(t>0)  p[m].cost=t;
                else p[m].cost=0;
                m++;
            }
        }
        printf("%.3lf\n",kruskal());
    }
    return 0;
}

