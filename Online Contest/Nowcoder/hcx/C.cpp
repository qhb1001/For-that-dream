#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=105;
const int maxx=1005;
int f[maxn],cnt[maxn];
int row[maxx],col[maxx];
int n;
void Init(){
    for(int i=0;i<=n;i++){
        f[i]=i;cnt[i]=1;
    }
}

int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}

void Union(int x,int y){
    int a=find(x),b=find(y);
    if(a==b) return ;
    if(cnt[a]>cnt[b])swap(a,b);
    f[b]=a;
    cnt[b]+=cnt[a];
}

int main(){
    scanf("%d",&n);
    int ans=0;
    int x,y;
    Init();
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        if(row[x]==0&&col[y]==0){
            row[x]=i;col[y]=i;
        }
        else{
            if(row[x])
                Union(i,row[x]);
            if(col[y])
                Union(i,col[y]);
        }
        row[x]=i;col[y]=i;//!!!!
    }

    for(int i=1;i<=n;i++){
        if(f[i]==i) ans++;
    }
    printf("%d\n",ans-1);
    return 0;
}
