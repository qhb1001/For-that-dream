#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=2e4+10;
struct Island{
    int x,y;
}arr[220];
int f[220],cnt[220];
struct ty{
    int u,v;
    double cost;
}p[maxn];
int n,m;
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

int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        Init();
        for(int i=1;i<=n;i++){
            scanf("%d%d",&arr[i].x,&arr[i].y);
        }
        m=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                p[m].u=i;p[m].v=j;
                double x=(arr[j].x-arr[i].x)*(arr[j].x-arr[i].x);
                double y=(arr[j].y-arr[i].y)*(arr[j].y-arr[i].y);
                double d=sqrt(x+y);
                p[m].cost=d;
                m++;
            }
        }

        sort(p+1,p+m,cmp);
        double res=0;
        for(int i=1;i<m;i++){
            if(p[i].cost<=1000&&p[i].cost>=10&&Union(p[i].u, p[i].v)){
                res+=p[i].cost;
            }
        }

        int cnt=0;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(f[i]==i) cnt++;
            if(cnt>1){
                flag=true;
                break;
            }
        }
        if(flag){
            printf("oh!\n");
        }
        else{
            printf("%.1lf\n",res*100);
        }
    }
    return 0;
}
