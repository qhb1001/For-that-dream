#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int maxn=4e6+10;
const int maxx=2010;
int f[maxx],cnt[maxx];
int node[maxn];
string s[maxx];
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
    cout<<"The highest possible quality is 1/"<<res<<"."<<endl;
}

int weight(int i,int j){
    int tmp=0;
    for(int k=0;k<7;k++){
        if(s[i][k]!=s[j][k])tmp++;
    }
    return tmp;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n&&n){
        for(int i=1;i<=n;i++) cin>>s[i];
        Init();
        
        m=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                p[m].u=i;p[m].v=j;
                p[m].cost=weight(i, j);
                m++;
            }
        }
        kruskal();
    }
    return 0;
}
