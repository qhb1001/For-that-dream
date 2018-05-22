#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll ans=0,m;
int a[maxn];
int cnt,n,k,l,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>l;
    m=1LL*n*k;
    for(int i=1;i<=m;i++) cin>>a[i];

    sort(a+1,a+m+1);
    if(a[n]-a[1]>l){
        cout<<0<<endl;
        return 0;
    }

    cnt=0;x=0;
    for(int i=m;i>=1;i--){
        ++cnt;
        if(cnt>=k&&a[i]-a[1]<=l){
            cnt-=k;
            ans+=a[i];
            x++;
        }
        if(x==n) break;
    }
    cout<<ans<<endl;
    return 0;
}
