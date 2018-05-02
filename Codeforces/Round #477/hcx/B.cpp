#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int s[maxn];
ll sums[maxn];
int n,a,b,x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a>>b;
    if(a==b){
        cout<<n-1<<endl;
        return 0;
    }

    cin>>x;
    ll sum;
    for(int i=1;i<n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n);
    int ans=n;
    sum=x;
    int idx=1;
    while(1){
        if(1LL*x*a/sum<b) break;
        sum+=s[idx++];
        ans--;
        if(ans==0) break;
    }
    cout<<ans<<endl;
    return 0;
}
