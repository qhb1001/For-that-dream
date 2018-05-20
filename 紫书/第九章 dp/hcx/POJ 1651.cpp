#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=105;
const int INF=0x3f3f3f3f;
int a[maxn];
int d[maxn][maxn];
bool vis[maxn][maxn];
int n;
void dfs(int i,int j){
//    cout<<endl<<i<<" "<<j<<" "<<d[i][j]<<endl;
    if(vis[i][j]) return ;
    if(i==j){
        d[i][j]=0;
        vis[i][j]=1;
        return ;
    }
    int tmp=INF;
    for(int k=i;k<j;k++){
        if(!d[i][k]) dfs(i, k);
        if(!d[k+1][j]) dfs(k+1,j);
//        cout<<i<<" "<<k<<" "<<j<<" "<<d[i][k]<<" "<<d[k+1][j]<<" "<<a[i]*a[k+1]*a[j+1]<<" "<<d[i][k]+d[k+1][j]+a[i]*a[k+1]*a[j+1]<<endl;
        tmp=min(tmp,d[i][k]+d[k+1][j]+a[i]*a[k+1]*a[j+1]);
    }
    d[i][j]=tmp;
    vis[i][j]=1;
//    cout<<i<<" "<<j<<" "<<d[i][j]<<endl;
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    dfs(1,n-1);
    cout<<d[1][n-1]<<endl;
    return 0;
}
