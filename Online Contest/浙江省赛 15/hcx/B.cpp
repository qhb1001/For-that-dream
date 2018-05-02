#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll D[maxn],S[maxn];
map<ll,int>m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--){
        m.clear();
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin>>D[i];
        }
        for(int i=0;i<n;i++){
            ll x;cin>>x;
            S[i]=x-D[i];
        }
        int ans=0;
        for(int i=0;i<n;i++){
            m[S[i]]++;
            ans=max(m[S[i]],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
