#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=55;
const int INF=1e9;
int d[maxn][maxn];
bool vis[maxn][maxn];
int a[maxn];
int n,l;
void dfs(int i,int j){
//    cout<<endl<<i<<" "<<j<<endl;
    if(vis[i][j]) return ;
    if(i==j-1){
        d[i][j]=0;
        vis[i][j]=1;
        return ;
    }
    
    int tmp=INF;
    for(int k=i+1;k<j;k++){
        if(!vis[i][k]) dfs(i,k);
        if(!vis[k][j]) dfs(k,j);
//        cout<<i<<" "<<k<<" "<<j<<" "<<d[i][k]<<" "<<d[k][j]<<" "<<a[j]-a[i]<<endl;
        if(tmp>d[i][k]+d[k][j]+a[j]-a[i]){
//            cout<<"*"<<i<<" "<<k<<" "<<j<<" "<<d[i][k]<<" "<<d[k][j]<<" "<<a[j]-a[i]<<endl;
        }
        tmp=min(tmp,d[i][k]+d[k][j]+a[j]-a[i]);
    }
    d[i][j]=tmp;
    vis[i][j]=1;
//    cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
    return ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>l){
        if(!l) break;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[0]=0;
        a[n+1]=l;
        memset(vis,0,sizeof(vis));
        dfs(0,n+1);
        cout<<"The minimum cutting is "<<d[0][n+1]<<"."<<endl;
    }
    return 0;
}
