#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int vis[10];
char map[10][10];
int n, k;
int ans;
void dfs(int r, int sum){
    if(r > n){
        return;
    }
    if(sum == k){
        ans ++;
        return;
    }
    for(int j=0; j<n; j++){
        if(map[r][j] == '#' && !vis[j]){
            vis[j] = 1;
            dfs(r+1, sum+1);
            vis[j] = 0;
        }
    }
    dfs(r+1, sum);
}
int main(){
    while(~scanf("%d%d",&n,&k) && n != -1){
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++){
            cin>>map[i];
        }
        ans = 0;
        dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
