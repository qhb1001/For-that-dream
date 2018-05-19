#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=105;
struct ty{
    int a,b,c;
}spa[maxn];
int d[maxn][3];
int a[3];
int n,kase=0;
int dfs(int idx,int k){
//    cout<<idx<<" "<<k<<endl;
    if(d[idx][k]) return d[idx][k];
    int tmp,ans;
    int a,b;
    if(k==0){
        a=spa[idx].b;
        b=spa[idx].c;
        tmp=spa[idx].a;
    }
    else if(k==1){
        a=spa[idx].a;
        b=spa[idx].c;
        tmp=spa[idx].b;
    }
    else{
        a=spa[idx].a;
        b=spa[idx].b;
        tmp=spa[idx].c;
    }
    ans=0;
    int aa,bb;
    
    for(int i=1;i<=n;i++){
        aa=spa[i].b;
        bb=spa[i].c;
        if(aa<a&&bb<b){
            ans=max(ans,dfs(i,0));
        }
        
        aa=spa[i].a;
        bb=spa[i].c;
        if(aa<a&&bb<b){
            ans=max(ans,dfs(i,1));
        }
        
        aa=spa[i].a;
        bb=spa[i].b;
        if(aa<a&&bb<b){
            ans=max(ans,dfs(i,2));
        }
    }
//    cout<<tmp<<" "<<ans<<endl;
    d[idx][k]=tmp+ans;
//    cout<<d[idx][k]<<endl;
    return d[idx][k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        if(!n) break;
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++){
            cin>>a[0]>>a[1]>>a[2];
            sort(a,a+3);
            spa[i].a=a[0];spa[i].b=a[1];spa[i].c=a[2];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++){
                if(!d[i][j]){
                    ans=max(ans,dfs(i, j));
//                    cout<<i<<" "<<j<<" "<<ans<<endl;
                }
            }
        }
        cout<<"Case "<<++kase<<": maximum height = "<<ans<<"\n";
    }
    return 0;
}
