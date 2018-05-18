#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
struct ty{
    int idx;
    int v=0;
}Node[maxn];
int cnt[maxn];
int ans[maxn];
int f[maxn];
int n,k,x,y;
bool cmp(ty a,ty b){
    if(a.v==b.v)
        return a.idx<b.idx;
    return a.v<b.v;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>Node[i].v;
        Node[i].idx=i;
    }
    while(k--){
        cin>>x>>y;
        if(Node[x].v>Node[y].v)
            cnt[x]++;
        if(Node[x].v<Node[y].v)
            cnt[y]++;
    }

    sort(Node+1,Node+1+n,cmp);
    x=1;
    for(int i=1;i<=n;i++){
        if(Node[i].v==Node[i-1].v)
            x++;
        else x=1;
        f[i]-=x;
    }
    for(int i=1;i<=n;i++){
//        cout<<Node[i].idx<<" "<<f[i]<<" "<<cnt[Node[i].idx]<<endl;
        ans[Node[i].idx]=(i+f[i])-cnt[Node[i].idx];
    }
    for(int i=1;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<ans[n]<<endl;
    return 0;
}
