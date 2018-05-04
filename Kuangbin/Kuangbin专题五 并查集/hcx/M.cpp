#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+5;
int f[maxn],cnt[maxn];
bool vis[maxn];
int a,b;
void Init(){
    for(int i=0;i<maxn;i++){
        f[i]=i;cnt[i]=1;
    }
}

int Find(int x){
    return x==f[x]?x:f[x]=Find(f[x]);
}

bool Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(a==b){
        return false;
    }
    if(cnt[a]<cnt[b]){
        f[a]=b;
        cnt[a]+=cnt[b];
    }
    else{
        f[b]=a;
        cnt[b]+=cnt[a];
    }
    return true;
}

int main(){
    bool flag=false;
    Init();
    memset(vis, 0, sizeof(vis));
    int tmp;
    while(cin>>a>>b){
        if(a==-1)break;
        if(a==0){
            cout<<"Yes"<<endl;
            continue;
        }
        tmp=a;
        vis[a]=vis[b]=1;
        if(a!=b&&!Union(a, b)) flag=true;
        while(cin>>a>>b){
            vis[a]=vis[b]=1;
            if(a==0){
                for(int i=1;i<maxn;i++){
                    if(vis[i]&&Find(tmp)!=Find(i)){
                        flag=true;
                        break;
                    }
                }
                if(flag) cout<<"No"<<endl;
                else cout<<"Yes"<<endl;
                break;
            }
            if(a==b){
                continue;
            }
            if(!Union(a, b)) flag=true;
        }
        flag=false;
        Init();
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
