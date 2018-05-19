#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[55];
bool vis[1005];
bool ans[55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=n;i>=1;i--){
        if(!vis[a[i]]){
            vis[a[i]]=1;
            ans[i]=1;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    bool flag=false;
    for(int i=1;i<=n;i++){
        if(ans[i])
            if(!flag) flag=true,cout<<a[i];
            else cout<<" "<<a[i];
    }
    cout<<endl;
    return 0;
}
