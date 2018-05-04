#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=1e4+5;
bool vis[maxn],vis1[maxn];
vector<int>G[maxn];
map<string,int>mp;
bool dfs(int x){
    int len=G[x].size();
    for(int i=0;i<len;i++){
        if(vis[G[x][i]]) return true;
        if(vis1[G[x][i]]) continue;
        vis[G[x][i]]=1;
        if(dfs(G[x][i]))return true;
        vis[G[x][i]]=0;
        vis1[G[x][i]]=1;
    }
    return false;
}

int main(){
    int n;scanf("%d",&n);
    string A,type,B;
    int a,b,cnt=1;
    mp.clear();
    for(int i=0;i<n;i++){
        cin>>A>>type>>B;
        if(type=="<")swap(A, B);
        if(mp.count(A)==0) mp[A]=cnt++;
        if(mp.count(B)==0) mp[B]=cnt++;
        a=mp[A]; b=mp[B];
        G[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!vis1[i]){
            if(dfs(i)){
                cout<<"impossible\n";
                return 0;
            }
        }
    }
    cout<<"possible\n";
    return 0;
}
