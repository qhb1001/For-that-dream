#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int aa[1005];
ll ans=0;
int main(){
    int n,a,b,c,t;
    cin>>n>>a>>b>>c>>t;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        aa[x]++;
    }
    if(b<c){
        int k=0;
        for(int i=1;i<=t;i++){
            ans+=k*(c-b);
            k+=aa[i];
        }
        ans+=n*a;
    }
    else{
        ans=n*a;
    }
    cout<<ans<<endl;
    return 0;
}
