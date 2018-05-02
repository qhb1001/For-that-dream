#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=1e5+10;
int t[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    int m=(n+1)/2;
    int x;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(x-i+1>=1)
            t[x-i+1]++;
//        cout<<x-i+1<<endl;
    }
    for(int i=m+1;i<=n;i++){
        cin>>x;
        if(x-n+i>=1)
            t[x-n+i]++;
//        cout<<x-n+i<<endl;
    }
    int ans=0;
    for(int i=1;i<=100000;i++){
        ans=max(ans,t[i]);
    }
    ans=n-ans;
    printf("%d\n",ans);
    return 0;
}
