#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue<int,vector<int> ,greater<int> >q;
int a[310];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll ans=0,cnt=1;
    while(cnt<=k) q.push(a[cnt++]);
    ll sum=0;
    while(!q.empty()){
        sum+=q.top();q.pop();
        ans+=sum;
        if(cnt<=n) q.push(a[cnt++]);
    }
    cout<<ans<<endl;
    return 0;
}
