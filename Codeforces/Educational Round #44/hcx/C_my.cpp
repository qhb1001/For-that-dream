#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll ans=0,m;
ll a[maxn];
ll cnt,n,k,l,x;
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
    ll i;
    for(i=n+1;i<=m;i++){
        if(a[i]-a[1]>l) break;
        if(i>m-k+1) break;
    }
    i--;
//    for(int j=1;j<=m;){
//        for(int y=1;y<=k;y++,j++)
//            cout<<a[j]<<" ";
//        cout<<endl;
//    }
//    cout<<i<<endl;
    cnt=1;
    for(;i>=1;){
        ans+=a[i];
//        cout<<"a[i]: "<<a[i]<<endl;
        i--;
        // n-cnt<=i<=(n-cnt-1)*k+1
        x=(n-cnt-1)*k+1;
        i=min(i,x);
//        cout<<i<<endl;
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}
