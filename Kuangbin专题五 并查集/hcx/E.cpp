#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5e4+5;
int f[3*maxn],cnt[3*maxn];
int n;
void Init(){
    for(int i=1;i<=n;i++){
        f[i]=i;f[maxn+i]=maxn+i;f[2*maxn+i]=2*maxn+i;
        cnt[i]=cnt[maxn+i]=cnt[2*maxn+i]=1;
    }
}

int Find(int x){
    if(x!=f[x]){
        f[x]=Find(f[x]);
    }
    return f[x];
}

void Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(a==b) return ;
    if(cnt[a]<cnt[b]){
        f[a]=b;
        cnt[a]+=cnt[b];
    }
    else{
        f[b]=a;
        cnt[b]+=cnt[a];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;cin>>n>>k;
    Init();
    int ans=0;
    for(int i=1;i<=k;i++){
        int d,x,y;cin>>d>>x>>y;
        if(x>n||y>n){
            ans++;continue;
        }
        if(d==2&&x==y){
            ans++;continue;
        }
        
        if(d==1){
            if(Find(x)==Find(y+maxn)||Find(x)==Find(y+2*maxn)){
                //                cout<<i<<" "<<1<<" "<<Find(x)<<" "<<Find(y+2*maxn)<<" "<<Find(y)<<" "<<Find(x+2*maxn)<<endl;
                ans++;continue;
            }
            Union(x, y);
            Union(x+maxn,y+maxn);
            Union(x+2*maxn,y+2*maxn);
        }
        else{
            if(Find(x)==Find(y)||Find(x)==Find(y+2*n)){
                //                cout<<i<<" "<<2<<" "<<Find(x)<<" "<<Find(y+maxn)<<" "<<Find(y)<<" "<<Find(x+maxn)<<endl;
                ans++;continue;
            }
            Union(x, y+maxn);
            Union(x+maxn, y+2*maxn);
            Union(x+2*maxn, y);
        }
    }
    cout<<ans<<endl;
    return 0;
}
