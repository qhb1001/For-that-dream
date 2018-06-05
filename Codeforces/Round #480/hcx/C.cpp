#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
int vis[300];
int ans[maxn];
int n,k,p,tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis, -1, sizeof(vis));
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>p;
        tmp=max(0,p-k+1);
//        cout<<"t: "<<tmp<<endl;
        if(vis[p]!=-1){
//            cout<<1<<endl;
            ans[i]=vis[p];
        }else if(vis[tmp]==-1){
//            cout<<2<<endl;
            ans[i]=tmp;
            for(int j=tmp;j<=p;j++)
                vis[j]=tmp;
        }else{
            int idx;
            for(idx=tmp;idx<=p;idx++){
                if(vis[idx]==-1) break;
                if(p-vis[idx]+1<=k) break;
            }
//            cout<<"idx: "<<idx<<endl;
            ans[i]=idx;
            for(int j=idx;j<=p;j++){
                vis[j]=idx;
            }
        }
    }
    cout<<ans[0];
    for(int i=1;i<n;i++)
        cout<<" "<<ans[i];
    cout<<endl;
    return 0;
}
