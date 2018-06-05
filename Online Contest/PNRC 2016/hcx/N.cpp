#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int maxn=15;
ll b[maxn],p[maxn];
set<ll>ans;
set<ll>::iterator it;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int cnt=1;
    for(int i=0;i<m;i++) cnt*=3;

    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<m;i++) cin>>p[i];

    sort(p,p+m);

    for(int i=0;i<cnt;i++){
        int now=i;

        ll l=0,r=0;
        for(int i=0;i<m;i++){
            if(now%3==0) l+=p[i];
            else if(now%3==1) r+=p[i];
            now/=3;
        }

        if(l!=r) continue;
        for(int i=0;i<n;i++){
            ans.insert(b[i]+l+r);
        }
    }

    for(it=ans.begin();it!=ans.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}
