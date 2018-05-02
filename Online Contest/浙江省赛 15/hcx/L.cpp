#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=105;
struct ty{
    string s;
    ll w;
}b[maxn];
bool cmp(ty a,ty b){
    if(a.w==b.w){
        return a.s<b.s;
    }
    return a.w>b.w;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        int n,m;cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>b[i].s>>b[i].w;
        }
        sort(b,b+n,cmp);
        string ans=b[0].s;
        ll x=m;
        ll sum=b[0].w*x;
        x--;
        for(int i=1;i<m;i++){
            sum+=b[i].w*x;
            ans+=" ";
            ans+=b[i].s;
            x--;
        }
        cout<<sum<<" "<<ans<<endl;
    }
    return 0;
}
