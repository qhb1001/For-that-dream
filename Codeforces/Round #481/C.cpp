#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
ll a[maxn];
int f,n,m;
ll k;
ll sum[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    while(m--){
        cin>>k;
        int pos=lower_bound(sum, sum+1+n, k)-(sum+1);
        cout<<pos+1<<" "<<k-sum[pos]<<endl;
    }
    return 0;
}
