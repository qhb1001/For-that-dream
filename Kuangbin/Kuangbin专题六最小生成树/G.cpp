#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int maxx=510;
int f[maxx],cnt[maxx];
double dis[maxx];
struct cells{
    double x,y;
}Node[maxx];
struct ty{
    int u,v;
    double cost;
}p[maxn];
int m,ss,pp;

bool cmp(ty a,ty b){
    return a.cost<b.cost;
}

void Init(){
    for(int i=1;i<=pp;i++){
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
    memset(dis, 0, sizeof(dis));
    sort(p+1,p+m,cmp);
//    for(int i=1;i<m;i++){
//        cout<<p[i].cost<<endl;
//    }
    int idx=0;
    for(int i=1;i<m;i++){
        if(Union(p[i].u, p[i].v)){
            dis[idx++]=p[i].cost;
            if(idx==pp-1){
                break;
            }
        }
    }
//    for(int i=0;i<pp-1;i++)
//        cout<<dis[i]<<endl;
    printf("%.2lf\n",dis[pp-1-ss]);
    return ;
}

double dist(int i,int j){
    double x=Node[i].x-Node[j].x;
    double y=Node[i].y-Node[j].y;
    return sqrt(x*x+y*y);
}

int main() {
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d",&ss,&pp);
        Init();
        for(int i=1;i<=pp;i++){
            cin>>Node[i].x>>Node[i].y;
        }
        m=1;
        for(int i=1;i<=pp;i++){
            for(int j=i+1;j<=pp;j++){
                double dd=dist(i, j);
                p[m].u=i;p[m].v=j;
                p[m].cost=dd;
                m++;
            }
        }
        kruskal();
    }
    return 0;
}
